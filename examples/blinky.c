#include "Serial328.h"
#include "Delay328.h"
#include <avr/io.h>

int main(void)
{
  Serial_begin(9600);

  // Set pin mode to output
  DDRB |= (1 << PB5);
  while (1)
  {
    PINB |= (1 << PINB5);
    delay(1);
  }
  return 0;
}
