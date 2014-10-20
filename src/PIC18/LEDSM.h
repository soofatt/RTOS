#ifndef LEDSM_H
#define LEDSM_H

typedef enum {
	LED_ON,
  LED_OFF
} LEDState;

typedef struct{
  LEDState state;
  unsigned long currentClock;
}

void LEDStateMachine(LEDState *statePtr);

#endif // LEDFSM_H
