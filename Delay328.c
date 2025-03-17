#include "Delay328.h"

void delay(int seconds)
{
  TCNT1 = getCounterValue(seconds);
  TCCR1A = 0b00000000;
  TCCR1B = 0b00000101; // Prescaler = 1024
  while (1)
  {
    if (TIFR1 & (1 << TOV1))
    {
      TIFR1 |= (1 << TOV1);
      TCCR1B = 0b11111111;
      break;
    }
  }
}

uint32_t getCounterValue(uint16_t timeDelaySeconds)
{
  uint32_t numTicks = (1 / timeDelaySeconds) / 0.000065;
  return 65536 - numTicks;
}