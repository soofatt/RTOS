#include "Clock.h"
#include "../18c.h"
#include "TCB.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"
#include "Interrupt.h"

volatile unsigned long clock = 0;

#if !(defined(__XC) || defined(__18CXX))
  #include "timers.h"
#else
    #include <timers.h>
#endif // __18CXX

char stackPtrH, stackPtrL;
char topOfStackH, topOfStackL;
uint16 stackPointerTemp;
TCB *TCBtemp;

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
#pragma interruptlow timer0isr
void timer0isr(){

_asm
    movff TOSH, topOfStackH
    movff TOSL, topOfStackL
_endasm
    
    //save all above into runningTCB

    //get highest priority from linked list

    //insert the runningTCB into linked list

    //restore all data in high priority task to TOS,BSR,WREG,STATUS
    // check FSR2, FSR1, (check only)FSR0(all low & high),TBLPTRH/L,TABLAT,PRODH/L,
    // WREG, BSR, STATUS
    //return from interrupt
        
    //runningTCB->stackPointer = (uint16)((topOfStackH << 8) + topOfStackL);
    runningTCB->stackPointer = (((uint16)topOfStackH) << 8) | topOfStackL;
    stackPointerTemp = runningTCB->stackPointer;
    TCBtemp = removeFromHeadPriorityLinkedList(readyQueue);
    addPriorityLinkedList(readyQueue, runningTCB, compare);
    runningTCB = TCBtemp;
    topOfStackL = (runningTCB->stackPointer) & 0x00ff;
    topOfStackH = runningTCB->stackPointer >> 8;

_asm
    movf topOfStackL, 0, ACCESS
    movwf TOSL, ACCESS
    movf topOfStackH, 0, ACCESS
    movwf TOSH, ACCESS
_endasm

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