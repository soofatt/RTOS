#include <stdio.h>
#include <malloc.h>
#include "PriorityLinkedList.h"

PriorityLinkedList *createPriorityLinkedList(){
  PriorityLinkedList *list = malloc(sizeof(PriorityLinkedList));
  list->head = NULL;
  
  return list;
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
  
  return temp;
}