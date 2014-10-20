#include "UARTLoopback.h"

void initUartLoopback(LoopbackData *data){
  
}

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