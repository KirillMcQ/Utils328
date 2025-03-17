#ifndef DELAY328_H
#define DELAY328_H

#include <stdio.h>
#include <avr/io.h>

void delay(int seconds);
uint32_t getCounterValue(uint16_t timeDelaySeconds);

#endif