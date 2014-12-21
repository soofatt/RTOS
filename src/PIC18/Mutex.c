#include "Mutex.h"
#include "PreemptiveOS.h"
#include <stdio.h>

extern TCB *runningTCB;

void initMutex(Mutex *mutex){
  mutex->count = 1;
  mutex->owner = NULL;
  mutex->waitingQueue.head = NULL;
  mutex->waitingQueue.tail = NULL;
}

int acquireMutex(Mutex *mutex){
  if(mutex->owner == NULL){
    mutex->owner = runningTCB;
    mutex->count--;
    return 1;
  }
  else if(runningTCB == mutex->owner){
    mutex->count--;
    return 1;
  }
  else{
    addPriorityLinkedList(&mutex->waitingQueue, runningTCB, compare);
    return 0;
  }
}

void releaseMutex(Mutex *mutex){
  if(runningTCB == mutex->owner){
    mutex->count++;
    if(mutex->count == 1)
      mutex->owner = removeFromHeadPriorityLinkedList(&mutex->waitingQueue);
  }
}