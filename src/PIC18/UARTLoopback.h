#ifndef UARTLoopback_H
#define UARTLoopback_H

typedef enum {
	WAIT_DATA,
  WAIT_TO_TX
} LoopbackState;

void uartLoopbackSM(LoopbackState *statePtr);

#endif // UARTLoopback_H
