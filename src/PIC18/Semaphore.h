#ifndef Semaphore_H
#define Semaphore_H

#include "PriorityLinkedList.h"

typedef struct Semaphore Semaphore;
struct Semaphore{
	int counter;
	int maxCounter;
	PriorityLinkedList waitingQueue;
};

void initCountingSemaphore(Semaphore *semaphore, int initCount);
void initBinarySemaphore(Semaphore *semaphore);
int downSemaphore(Semaphore *semaphore);
void upSemaphore(Semaphore *semaphore);

#endif // Semaphore_H
