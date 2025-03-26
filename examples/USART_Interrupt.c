#include "Serial328.h"
#include "Delay328.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
  sei();              // Enable interrupts
  DDRB |= (1 << PB5); // Set user LED to output
  Serial_begin(9600);

  while (1)
  {
    if (PINB & (1 << PINB5))
    {
      Serial_print("Turning the LED off!");
    }
    else
    {
      Serial_print("Turning the LED on!");
    }
    delay(4);
  }
  return 0;
}

// Toggle the LED when there was a successful USART TX
ISR(USART_TX_vect)
{
  PINB |= (1 << PINB5); // Toggle LED
}