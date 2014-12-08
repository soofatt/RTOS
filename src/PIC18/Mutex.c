#include "Mutex.h"
#include <stdio.h>

void initMutex(Mutex *mutex){
  mutex->count = 1;
  mutex->owner = NULL;
  mutex->waitingQueue = NULL;
}