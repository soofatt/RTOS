#include <stdio.h>
#include <stdlib.h>
#include "Loopback.h"
#include "../18c.h"
#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
#endif // __18CXX

void usartLoopback() {
  unsigned char data;
  while(!DataRdyUSART());
  data = ReadUSART();
  while(BusyUSART());
  WriteUSART(data);
}