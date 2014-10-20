#ifndef LEDSM_H
#define LEDSM_H

typedef enum {
  LED_START,
	LED_ON,
  LED_OFF
} LEDState;

typedef struct LEDData LEDData;
struct LEDData{
  LEDState state;
  unsigned long currentClock;
};

void LEDStateMachine(LEDData *data);
void initLEDStateMachine(LEDData *data);

#endif // LEDFSM_H
