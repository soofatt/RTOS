#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"
#include "../18c.h"

TCB *runningTCB;
TCB allTCB[3];
PriorityLinkedList readyQueue;
unsigned char stacks[2][80];
//unsigned char stackOne[80];
//unsigned char stacktwo[80];

void createTask(TCB tcbs[], int index, void (*task)(void)){
    tcbs[index].task = (uint16)task;
    tcbs[index].next = NULL;
    tcbs[index].stackPointer = (uint16)&stacks[index-1];
    tcbs[index].priority = 0;
    tcbs[index].taskID = index;
    addPriorityLinkedList(&readyQueue, &tcbs[index], compare);
}

void initPreemptiveMultitasking(void) {
    readyQueue.head = NULL;
    readyQueue.tail = NULL;
    runningTCB = &allTCB[0];
    runningTCB->next = NULL;
    createTask(allTCB, 1, &taskOne);
    createTask(allTCB, 2, &taskTwo);
}

void taskOne(){
    int i = 0;
    while(i != 255){
        i++;
    }
}

void taskTwo(){
    int j = 0;
    while(j != 255){
        j++;
    }
}
