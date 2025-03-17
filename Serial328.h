#ifndef SERIAL328_H
#define SERIAL328_H

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdbool.h>

#define FOSC 16000000

void Serial_begin(unsigned int baud);
void Serial_transmit(unsigned char data);
unsigned char Serial_recieve(void);
void Serial_print(unsigned char str[]);
bool Serial_available();

#endif