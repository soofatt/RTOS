#ifndef PriorityLinkedList_H
#define PriorityLinkedList_H

typedef struct TCB TCB;
struct TCB{
  struct TCB *next;
  char priority;
  char PC[3];
  int dataStack;
  char status;
};

typedef struct PriorityLinkedList PriorityLinkedList;
struct PriorityLinkedList{
  TCB *head;
  TCB *tail;
};

PriorityLinkedList *createPriorityLinkedList();
int compare(void *, void *);
void addPriorityLinkedList(PriorityLinkedList *list, void *data, int compare(void *, void *));
void *removePriorityLinkedList(PriorityLinkedList *list, void *data, int compare(void *, void *));
void *removeFromHeadPriorityLinkedList(PriorityLinkedList *list);

#endif // PriorityLinkedList_H
