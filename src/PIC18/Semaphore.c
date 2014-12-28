#include "Semaphore.h"
#include "PreemptiveOS.h"
#include "TCB.h"
#include "Interrupt.h"
#include <stdio.h>
// ignore scheduler for PC test
#if !(defined(__XC) || defined(__18CXX))
  #define timer0isr()
#else
  #include Clock.h
#endif // __18CXX
int blockStatus; //For PC test, comment out in MPLAB

void initCountingSemaphore(Semaphore *semaphore, int initCount){
  semaphore->maxCounter = initCount;
  semaphore->counter = semaphore->maxCounter;
  semaphore->waitingQueue.head = NULL;
  semaphore->waitingQueue.tail = NULL;
}

void initBinarySemaphore(Semaphore *semaphore){
  semaphore->maxCounter = 1;
  semaphore->counter = semaphore->maxCounter;
  semaphore->waitingQueue.head = NULL;
  semaphore->waitingQueue.tail = NULL;
}

int downSemaphore(Semaphore *semaphore){
  disableGlobalInterrupt();
  if(semaphore->counter > 0){
    semaphore->counter--;
    enableGlobalInterrupt();
    return 1;
  }
  else{
    addPriorityLinkedList(&semaphore->waitingQueue, runningTCB, compare);
    blockStatus = 1;
    timer0isr();
    enableGlobalInterrupt();
    return 0;
  }  
}

void upSemaphore(Semaphore *semaphore){
  TCB *temp;
  disableGlobalInterrupt();
  if(semaphore->waitingQueue.head != NULL){
    temp = removeFromHeadPriorityLinkedList(&semaphore->waitingQueue);
    addPriorityLinkedList(&readyQueue, temp, compare);
  }
  else
    semaphore->counter++;
    
  enableGlobalInterrupt();
}