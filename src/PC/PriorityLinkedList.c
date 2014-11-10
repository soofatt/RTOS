#include <stdio.h>
#include <malloc.h>
#include "PriorityLinkedList.h"

PriorityLinkedList *createPriorityLinkedList(){
  PriorityLinkedList *list = malloc(sizeof(PriorityLinkedList));
  list->head = NULL;
  
  return list;
}

int compare(void *element, void *elementOfInterest){
  TCB *elementToInsert = (TCB *)element;
  TCB *elementInList = (TCB *)elementOfInterest;
  
  if(elementToInsert->priority > elementInList->priority)
    return 1;
  else
    return 0;
}

void *removeFromHeadPriorityLinkedList(PriorityLinkedList *list){
  TCB *temp;
  temp = list->head;
  
  if(list->head->next == NULL){
    list->head = list->head->next;
    list->tail = NULL;
  }
  else{
    list->head = list->head->next;
  }
  temp->next = NULL;
  return temp;
}

void addPriorityLinkedList(PriorityLinkedList *list, void *data, int compare(void *, void *)){
	TCB *elementToInsert = (TCB *)data;
  
  if(list->head == NULL && list->tail == NULL){
		list->head = elementToInsert;
		list->tail = elementToInsert;
	}
	else{
	
	}

}