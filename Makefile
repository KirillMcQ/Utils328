main.elf: main.c
	avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o main.elf main.c Serial328.c Delay328.c

main.hex: main.elf
	avr-objcopy -O ihex main.elf main.hex

flash: main.hex
	avrdude -c arduino -p atmega328p -P /dev/cu.usbserial-AB0ONQRK -b 115200 -U flash:w:main.hex:i
	rm -f main.elf main.hex
