#include "unity.h"
#include "PriorityLinkedList.h"

void setUp(void){}

void tearDown(void){}

void test_createPriorityLinkedList_should_create_a_priorityLinkedList(void){
	PriorityLinkedList *list;
  
  list = createPriorityLinkedList();
  
  TEST_ASSERT_NOT_NULL(list);
  TEST_ASSERT_NULL(list->head);  
}

/*
 *          +----+
 *  head -->| #1 | --> NULL
 *          +----+
 *  tail -----^
 *
 */
void test_removeFromHeadPriorityLinkedList_given_1_element_point_to_NULL_head_should_point_to_NULL(void){
	TCB *result;
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCB1 = {.next = NULL, .priority = 10};
  
  list->head = &TCB1;
  list->tail = &TCB1;
  
  result = removeFromHeadPriorityLinkedList(list);
  
  TEST_ASSERT_NULL(list->head);
  TEST_ASSERT_NULL(list->tail);
  TEST_ASSERT_NULL(result->next);
  TEST_ASSERT_EQUAL(10, result->priority);
}