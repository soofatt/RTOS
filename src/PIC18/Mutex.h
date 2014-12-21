#ifndef Mutex_H
#define Mutex_H

#include "PriorityLinkedList.h"

typedef struct Mutex Mutex;
struct Mutex{
  char count;
  TCB *owner;
  PriorityLinkedList waitingQueue;
};

void initMutex(Mutex *mutex);
int acquireMutex(Mutex *mutex);
void releaseMutex(Mutex *mutex);

#endif // Mutex_H
