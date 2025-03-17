#include "Serial328.h"

void Serial_begin(unsigned int baud)
{
  int ubrr = FOSC / 16 / baud - 1;
  /*Set baud rate */
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  /*Enable receiver and transmitter */
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  /* Set frame format: 8data, 1stop bit */
  UCSR0C = (3 << UCSZ00);
}

void Serial_transmit(unsigned char data)
{
  /* Wait for empty transmit buffer */
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  /* Put data into buffer, sends the data */
  UDR0 = data;
}

bool Serial_available()
{
  return UCSR0A & (1 << RXC0);
}

unsigned char Serial_recieve(void)
{
  /* Wait for data to be received */
  while (!Serial_available())
    ;
  /* Get and return received data from buffer */
  return UDR0;
}

void Serial_print(unsigned char str[])
{
  for (int i = 0; i < strlen(str); i++)
  {
    Serial_transmit(str[i]);
  }
}