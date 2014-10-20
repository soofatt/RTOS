#include "LEDSM.h"

#define CLK_OV 488 //0.5s

static unsigned long clock;

void LEDStateMachine(LEDState *statePtr){
  switch(*statePtr){
    case LED_OFF:
      clock = getClock();
      if(clock <= CLK_OV)
        break;
      *statePtr = LED_ON;
        break;
        
    case LED_ON:
      clock = getClock();
      if(clock <= CLK_OV)
        break;
      *statePtr = LED_OFF;
        break;
      
    default:
      break;
  }
}