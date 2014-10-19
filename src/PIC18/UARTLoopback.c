#include "UARTLoopback.h"

void uartLoopbackSM(LoopbackState *statePtr){
  char data = 0x00;

  switch(*statePtr){
    case WAIT_DATA:
      if(DataRdyUSART() == 0)
        break;
      data = getcUSART();
      *statePtr = WAIT_TO_TX;
      break;

    case WAIT_TO_TX:
      if(BusyUSART() == 1)
        break;
      putcUSART(data);
      *statePtr = WAIT_DATA;
      break;
      
    default:
      break;
  }
}