#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"
#include "../18c.h"

TCB *runningTCB;
TCB allTCB[3];
PriorityLinkedList *readyQueue;
unsigned char stacks[2][80];
//unsigned char stackOne[80];
//unsigned char stacktwo[80];

void createTask(TCB tcbs[], int index, void(*task)(void)){
    addPriorityLinkedList(readyQueue, &tcbs[index], compare);
    tcbs[index].task = taskOne;
    tcbs[index].stackPointer = (uint16)&stacks[index-1];
    tcbs[index].priority = 0;
    tcbs[index].taskID = index;
}

void initPreemptiveMultitasking(void) {
    runningTCB = &allTCB[0];
    createTask(allTCB, 1, taskOne);
    createTask(allTCB, 2, taskTwo);
}

void taskOne(){
    
}

void taskTwo(){

}
