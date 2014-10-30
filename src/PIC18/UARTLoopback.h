#ifndef UARTLoopback_H
#define UARTLoopback_H

typedef enum {
	WAIT_DATA,
  WAIT_TO_TX
} LoopbackState;

typedef struct LoopbackData LoopbackData;
struct LoopbackData{
  LoopbackState state;
  char dataByte;
};

void uartLoopbackSM(LoopbackData *data);
void initUartLoopback(LoopbackData *data);

#endif // UARTLoopback_H
