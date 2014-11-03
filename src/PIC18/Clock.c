#include "Clock.h"
#include "../18c.h"
//#include "../TCB.h"
#include "timers.h"
#include "Interrupt.h"

char workingReg, bankSelectReg, statusReg;
char topOfStackU, topOfStackH, topOfStackL;
TCB runningTCB;

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

#asm
    movwf _workingReg
    movff STATUS, _statusReg
    movff BSR, _bankSelectReg
    //movff TOSU, _topOfStackU
    //movff TOSH, _topOfStackH
    //movff TOSL, _topOfStackL
#endasm
    
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
char isTimer0Overflowed(){
    return INTCONbits.TMR0IF;
}

void clearTimer0OverflowFlag(){
  INTCONbits.TMR0IF = 0;
}