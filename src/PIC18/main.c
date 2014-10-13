#include <stdio.h>
#include <stdlib.h>
#include "Blinky.h"
#include "Loopback.h"
#include "../18c.h"
#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
#else
    #include <usart.h>
#endif // __18CXX

#pragma config OSC = INTIO67, PWRT = ON, WDT = OFF, LVP = OFF, DEBUG = ON

#define setFreq8MHz() (OSCCONbits.IRCF = 7)

#define configureUsartTo8Bits9600Baud() \
          OpenUSART(USART_TX_INT_OFF &  \
                    USART_RX_INT_OFF &  \
                    USART_ASYNCH_MODE & \
                    USART_EIGHT_BIT &   \
                    USART_CONT_RX &     \
                    USART_BRGH_HIGH, 51);

void main(void) {
  setFreq8MHz();
  configureUsartTo8Bits9600Baud();
  
  while(1) {
    usartLoopback();
    onLED();
  }

  CloseUSART();
}
