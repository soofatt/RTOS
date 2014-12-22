#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"
#include "../18c.h"

TCB *runningTCB;
TCB allTCB[3];
PriorityLinkedList readyQueue;
#pragma udata BIGDATA
    unsigned char stacks[2][200];
#pragma udata

void createTask(TCB tcbs[], int index, void (*task)(void)){
    tcbs[index].task = (uint16)task;
    tcbs[index].next = NULL;
    tcbs[index].stackPointer = (uint16)&stacks[index-1]+41;
    tcbs[index].priority = 0;
    tcbs[index].taskID = index;
    // stacks[index-1][12] = FSR2H;
    stacks[index-1][12] = ((uint16)stacks[index-1])>>8;
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
    while(i != 100000){
        i++;
    }
}

void taskTwo(){
    int j = 0;
    while(j != 100000){
        j++;
    }
}
