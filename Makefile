MCU = atmega328p
F_CPU = 16000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os
LDFLAGS = -mmcu=$(MCU)

SRC = main.c
OBJ = main.elf
HEX = main.hex

CUSTOMHEADERSERIALC = Serial328.c
CUSTOMHEADERDELAYC = Delay328.c

PORT = /dev/cu.usbserial-AB0ONQRK
BAUD = 115200
PROGRAMMER = arduino

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC) $(CUSTOMHEADERSERIALC) ${CUSTOMHEADERDELAYC}

$(HEX): $(OBJ)
	$(OBJCOPY) -O ihex $(OBJ) $(HEX)

flash: $(HEX)
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:$(HEX):i
	rm -f $(OBJ) $(HEX)
