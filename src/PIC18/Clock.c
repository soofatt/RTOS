#include "Clock.h"
#include "../18c.h"
//#include "../TCB.h"
#include "Interrupt.h"

volatile unsigned long clock = 0;

#if !(defined(__XC) || defined(__18CXX))
  #include "timers.h"
#else
    #include <timers.h>
#endif // __18CXX

char workingReg, bankSelectReg, statusReg;
char topOfStackU, topOfStackH, topOfStackL;
//TCB runningTCB;

void initClock(void){
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
unsigned long getClock(void){
  /*if(isTimer0Overflowed()){
    clock++;
    clearTimer0OverflowFlag();
  }*/
  return clock;
}
#pragma interrupt timer0isr
void timer0isr(){

_asm
    movwf workingReg, ACCESS
    movff STATUS, statusReg
    movff BSR, bankSelectReg
    //movff TOSU, _topOfStackU
    //movff TOSH, _topOfStackH
    //movff TOSL, _topOfStackL
_endasm
    
    //save all above into runningTCB

    //get highest priority from linked list

    //insert the runningTCB into linked list

    //restore all data in high priority task to TOS,BSR,WREG,STATUS

    //return from interrupt

    clock++;
    clearTimer0OverflowFlag();
}

//////////////////////////////////////////
// These functions are for internal use
//////////////////////////////////////////
char isTimer0Overflowed(void){
    return INTCONbits.TMR0IF;
}

void clearTimer0OverflowFlag(void){
  INTCONbits.TMR0IF = 0;
}

#pragma code high_vector = 0x08
void highPriorityIsr(void){
    _asm
    goto timer0isr
    _endasm
}