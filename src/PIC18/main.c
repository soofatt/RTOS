#include <stdio.h>
#include <stdlib.h>
#include "Clock.h"
#include "Blinky.h"
#include "SevenSeg.h"
#include "UARTLoopback.h"
//#include "LEDSM.h"
#include "Led2.h"
//#include "../TCB.h"
//#include "PreemptiveOS.h"
#include "../18c.h"

#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
  #include "spi.h"
#else
    #include <usart.h>
    #include <spi.h>
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

//extern TCB runningTCB;

void main(void) {
  Led2Data led2Data;
  LoopbackData loopbackData;
  SevenSegData sevenSegData;
  setFreq8MHz();
  configureUsartTo8Bits9600Baud();
  OpenSPI(SPI_FOSC_4, MODE_11, SMPEND);
  configureLED();
  //LEDData ledData;
  //initLEDStateMachine(&ledData);
  initClock();
  initUartLoopback(&loopbackData);
  initSevenSeg(&sevenSegData);
  turnOnSevenSeg();
  while(1){
      led2SM(&led2Data);
      sevenSegSM(&sevenSegData);
      uartLoopbackSM(&loopbackData);
  }
  CloseSPI();
  CloseUSART();
  //
  //
  //
  
  /*while(1) {
      
    
    //LEDStateMachine(&ledData);
    led2SM(&led2Data);
    sevenSegSM(&sevenSegData);
  }
  CloseSPI();
  CloseUSART();*/
}
