#include <stdio.h>
#include <stdlib.h>
#include "Blinky.h"
#include "SevenSeg.h"
#include "Clock.h"
#include "UARTLoopback.h"
#include "LEDSM.h"
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
  //setFreq8MHz();
  //configureUsartTo8Bits9600Baud();
  //LoopbackData loopbackData;
  //LEDData ledData;
  //initLEDStateMachine(&ledData);
  //initClock();
  //initUartLoopback(&loopbackData);
  //initSevenSeg();
  //turnOnSevenSeg();
  //TRISC = 0;
  OpenSPI(SPI_FOSC_4, MODE_11, SMPEND);
  while(1){
  WriteSPI(0x20);
  delay();}
  //while(1) {
      
      //uartLoopbackSM(&loopbackData);
      //LEDStateMachine(&ledData);
  //}
  CloseSPI();
  //CloseUSART();
}
