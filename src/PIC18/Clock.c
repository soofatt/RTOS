#include "Clock.h"
#include "../18c.h"
#include "timers.h"
#include "Interrupt.h"

void initClock(){
  clock = 0;
  enableGlobalInterrupt();
  OpenTimer0( TIMER_INT_ON &
              T0_8BIT &
              T0_SOURCE_INT &
              T0_PS_1_8 );
              
  INTCONbits.TMR0IF = 0;
}

/**
 * Return the micro-controller's clock since power-up. 1 clock
 * is roughly 1.024msec.
 */
unsigned long getClock(){
  /*if(isTimer0Overflowed()){
    clock++;
    clearTimer0OverflowFlag();
  }*/
  return clock;
}

void timer0isr(){
    clock++;
    clearTimer0OverflowFlag();
}

//////////////////////////////////////////
// These functions are for internal use
//////////////////////////////////////////
char isTimer0Overflowed(){
    return INTCONbits.TMR0IF;
}

void clearTimer0OverflowFlag(){
  INTCONbits.TMR0IF = 0;
}