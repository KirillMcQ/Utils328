#include "Serial328.h"
#include "Delay328.h"

int main(void)
{
  Serial_begin(9600);

  while (1)
  {
    Serial_print("Beginning 1 second delay.");
    delay(1);
    Serial_print("Delay finished.");
  }
  return 0;
}
