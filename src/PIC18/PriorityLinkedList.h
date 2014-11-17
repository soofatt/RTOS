#ifndef PriorityLinkedList_H
#define PriorityLinkedList_H

#include "TCB.h"

typedef struct PriorityLinkedList PriorityLinkedList;
struct PriorityLinkedList{
  TCB *head;
  TCB *tail;
};

PriorityLinkedList *createPriorityLinkedList();
int compare(void *element, void *elementOfInterest);
void addPriorityLinkedList(PriorityLinkedList *list, void *data, int compare(void *, void *));
void *removePriorityLinkedList(PriorityLinkedList *list, void *data, int compare(void *, void *));
void *removeFromHeadPriorityLinkedList(PriorityLinkedList *list);

#endif // PriorityLinkedList_H
