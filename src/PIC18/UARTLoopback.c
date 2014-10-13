#include "UARTLoopback.h"

void uartLoopbackSM(LoopbackState *statePtr){
  char data;

  switch(*statePtr){
    case WAIT_DATA:
      if(DataRdyUSART() == 0)
        break;
      data = getcUSART();
      *statePtr = WAIT_TO_TX;

    case WAIT_TO_TX:
      break;
    default:
      break;
  }
}