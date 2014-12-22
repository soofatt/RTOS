#include <stdio.h>
#include "PriorityLinkedList.h"

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
  
  if(list->head == NULL)
    return NULL;
  else if(list->head->next == NULL){
    list->head = NULL;
    list->tail = NULL;
  }
  else{
    list->head = list->head->next;
  }
  temp->next = NULL;
  
  return temp;
}

void addPriorityLinkedList(PriorityLinkedList *list, void *data, int compare(void *, void *)){
  TCB *elementToAdd = (TCB *)data;
  TCB *elementToCompare;
  TCB *elementBefore;
  if(list->head == NULL && list->tail == NULL){
    list->head = elementToAdd;
    list->tail = elementToAdd;
  }
  else{
    elementToCompare = list->head;
    while(compare(elementToAdd, elementToCompare) != 1){
      if(elementToCompare->next == NULL){
        elementToCompare->next = elementToAdd;
        list->tail = elementToAdd;
        return;
      }
      else{
        elementBefore = elementToCompare;
        elementToCompare = elementToCompare->next;
      }
    }
    if(compare(elementToAdd, elementToCompare)){
      if(elementToCompare == list->head){
        list->head = elementToAdd;
        elementToAdd->next = elementToCompare;
      }
      else{
        elementBefore->next = elementToAdd;
        elementToAdd->next = elementToCompare;
      }
    }
  }
}