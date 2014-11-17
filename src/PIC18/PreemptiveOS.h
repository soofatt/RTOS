#ifndef PreemptiveOS_H
#define PreemptiveOS_H

extern TCB *runningTCB;
extern PriorityLinkedList *readyQueue;

void initPreemptiveMultitasking(void);
void createTask(TCB tcbs[], int index, void (*task)(void));
void taskOne();
void taskTwo();

#endif // PreemptiveOS_H

