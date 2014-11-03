#include <stdio.h>
#include <stdlib.h>
//#include "../TCB.h"

//extern TCB runningTCB;

void initPreemptiveMultitasking(void) {
  setFreq8MHz();
  configureUsartTo8Bits9600Baud();
  //OpenSPI(SPI_FOSC_4, MODE_11, SMPEND);
  //configureLED();
  LoopbackData loopbackData;
  //LEDData ledData;
  Led2Data led2Data;
  SevenSegData sevenSegData;
  //initLEDStateMachine(&ledData);
  initClock();
  while(1){
  }
  //initUartLoopback(&loopbackData);
  //initSevenSeg(&sevenSegData);
  //turnOnSevenSeg();
  
  /*while(1) {
      
    uartLoopbackSM(&loopbackData);
    //LEDStateMachine(&ledData);
    led2SM(&led2Data);
    sevenSegSM(&sevenSegData);
  }
  CloseSPI();
  CloseUSART();*/
}
