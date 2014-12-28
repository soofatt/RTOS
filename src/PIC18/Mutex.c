#include "Mutex.h"
#include "PreemptiveOS.h"
#include "Interrupt.h"
#include <stdio.h>
// ignore scheduler for PC test
#if !(defined(__XC) || defined(__18CXX))
  #define timer0isr()
#else
  #include Clock.h
#endif // __18CXX
int blockStatus; //For PC test, comment out in MPLAB

void initMutex(Mutex *mutex){
  mutex->count = 1;
  mutex->owner = NULL;
  mutex->waitingQueue.head = NULL;
  mutex->waitingQueue.tail = NULL;
}

int acquireMutex(Mutex *mutex){
  disableGlobalInterrupt();
  if(mutex->owner == NULL){
    mutex->owner = runningTCB;
    mutex->count--;
    enableGlobalInterrupt();
    return 1;
  }
  else if(runningTCB == mutex->owner){
    mutex->count--;
    enableGlobalInterrupt();
    return 1;
  }
  else{
    addPriorityLinkedList(&mutex->waitingQueue, (void *)runningTCB, compare);
    blockStatus = 1;
    timer0isr();
    enableGlobalInterrupt();
    return 0;
  }
}

void releaseMutex(Mutex *mutex){
  disableGlobalInterrupt();
  if(runningTCB == mutex->owner){
    mutex->count++;
    if(mutex->count == 1){
      if(mutex->waitingQueue.head == NULL)
        mutex->owner = NULL;
      else{
        mutex->owner = removeFromHeadPriorityLinkedList(&mutex->waitingQueue);
        addPriorityLinkedList(&readyQueue, mutex->owner, compare);
      }
    }
  }
  enableGlobalInterrupt();
}