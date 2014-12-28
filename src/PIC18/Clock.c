#include "Clock.h"
#include "../18c.h"
#include "TCB.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"
#include "Interrupt.h"
#include "Types.h"
#include <stdio.h>

volatile unsigned long clock = 0;

#if !(defined(__XC) || defined(__18CXX))
  #include "timers.h"
#else
    #include <timers.h>
#endif // __18CXX

int blockStatus = 0;
uint8 fileSelectRegH, fileSelectRegL;
uint8 topOfStackH, topOfStackL;
uint16 fsrTemp = 0, stackPointerTemp = 0;
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
#pragma interruptlow timer0isr save = FSR2L

#pragma code high_vector = 0x08
void highPriorityIsr(void){
    _asm
    goto timer0isr
    _endasm
}

void timer0isr(){
  if(blockStatus == 1){
    disableGlobalInterrupt();
    TCBtemp = removeFromHeadPriorityLinkedList(&readyQueue);
    runningTCB = TCBtemp;

    topOfStackL = (runningTCB->task) & 0x00ff;
    topOfStackH = runningTCB->task >> 8;
    fileSelectRegL = (runningTCB->stackPointer) & 0x00ff;
    fileSelectRegH = runningTCB->stackPointer >> 8;

_asm
movff topOfStackH, WREG
movwf TOSH, ACCESS
movff topOfStackL, WREG
movwf TOSL, ACCESS
movff fileSelectRegH, WREG
movwf FSR1H, ACCESS
movff fileSelectRegL, WREG
movwf FSR1L, ACCESS
_endasm
    blockStatus = 0;
    enableGlobalInterrupt();
  }
  else{
_asm
movff TOSH, topOfStackH
movff TOSL, topOfStackL
movff FSR1H, fileSelectRegH
movff FSR1L, fileSelectRegL
_endasm
        
    runningTCB->priority = 0;
    runningTCB->next = NULL;

    runningTCB->task = ((uint16)(topOfStackH) << 8) | topOfStackL;
    runningTCB->stackPointer = ((uint16)(fileSelectRegH) << 8) | fileSelectRegL;

    //stackPointerTemp = runningTCB->task;
    //fsrTemp = runningTCB->stackPointer;
    TCBtemp = removeFromHeadPriorityLinkedList(&readyQueue);
    addPriorityLinkedList(&readyQueue, runningTCB, compare);
    runningTCB = TCBtemp;

    topOfStackL = (runningTCB->task) & 0x00ff;
    topOfStackH = runningTCB->task >> 8;
    fileSelectRegL = (runningTCB->stackPointer) & 0x00ff;
    fileSelectRegH = runningTCB->stackPointer >> 8;

_asm
movff topOfStackH, WREG
movwf TOSH, ACCESS
movff topOfStackL, WREG
movwf TOSL, ACCESS
movff fileSelectRegH, WREG
movwf FSR1H, ACCESS
movff fileSelectRegL, WREG
movwf FSR1L, ACCESS
_endasm
  }
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

