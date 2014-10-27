#include "UARTLoopback.h"
#include "../18c.h"

#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
#endif // __18CXX

#pragma config OSC = INTIO67, DEBUG = ON, LVP = OFF, WDT = OFF, PWRT = ON

//void initUartLoopback(LoopbackData *data){
//  data->state = WAIT_DATA;
//  data->dataByte = 0;
//}

void uartLoopbackSM(LoopbackData *data){

  switch(data->state){
    case WAIT_DATA:
      if(DataRdyUSART() == 0)
        break;
      data->dataByte = getcUSART();
      data->state = WAIT_TO_TX;
      break;

    case WAIT_TO_TX:
      if(BusyUSART() == 1)
        break;
      putcUSART(data->dataByte);
      data->state = WAIT_DATA;
      break;
      
    default:
      break;
  }
}