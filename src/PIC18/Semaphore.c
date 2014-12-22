#include "Semaphore.h"
#include "PreemptiveOS.h"
#include "TCB.h"
#include <stdio.h>

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
  if(semaphore->counter > 0){
    semaphore->counter--;
    return 1;
  }
  else{
    addPriorityLinkedList(&semaphore->waitingQueue, runningTCB, compare);
    return 0;
  }  
}

void upSemaphore(Semaphore *semaphore){
  TCB *temp;
  
  if(semaphore->waitingQueue.head != NULL){
    temp = removeFromHeadPriorityLinkedList(&semaphore->waitingQueue);
    addPriorityLinkedList(&readyQueue, temp, compare);
  }
  else
    semaphore->counter++;
}