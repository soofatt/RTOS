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

/*
 *          +----+     +----+
 *  head -->| #1 | --> | #2 | --> NULL
 *          +----+     +----+
 *  tail -----^
 *
 */
void test_removeFromHeadPriorityLinkedList_given_2_element_head_should_point_to_next_element(void){
	TCB *result;
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCB2 = {.next = NULL, .priority = 10};
  TCB TCB1 = {.next = &TCB2, .priority = 20};
  
  list->head = &TCB1;
  list->tail = &TCB2;
  
  result = removeFromHeadPriorityLinkedList(list);
  
  TEST_ASSERT_EQUAL(&TCB2, list->head);
  TEST_ASSERT_EQUAL(&TCB2, list->tail);
  TEST_ASSERT_EQUAL(&TCB1, result);
  TEST_ASSERT_EQUAL(20, result->priority);
  TEST_ASSERT_NULL(result->next);
}

void test_compare_should_compare_priority_of_two_elements_return_1_if_greater(void){
	TCB toInsert = {.priority = 2};
	TCB inList = {.priority = 1};
  int result;
  
  result = compare(&toInsert, &inList);
  
  TEST_ASSERT_EQUAL(1, result);
}

void test_compare_should_compare_priority_of_two_elements_return_0_if_lesser(void){
	TCB toInsert = {.priority = 1};
	TCB inList = {.priority = 2};
  int result;
  
  result = compare(&toInsert, &inList);
  
  TEST_ASSERT_EQUAL(0, result);
}

void test_compare_should_compare_priority_of_two_elements_return_0_if_equal(void){
	TCB toInsert = {.priority = 2};
	TCB inList = {.priority = 2};
  int result;
  
  result = compare(&toInsert, &inList);
  
  TEST_ASSERT_EQUAL(0, result);
}

/*
 *          +----+
 *  head -->| #1 | --> NULL
 *          +----+
 *  tail -----^
 *
 */
void test_addPriorityLinkedList_should_add_to_empty_list(void){
  TCB *result;
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCB = {.next = NULL, .priority = 20};
  
  list->head = NULL;
  list->tail = NULL;
  
  addPriorityLinkedList(list, &TCB, compare);
  
  TEST_ASSERT_EQUAL(&TCB, list->head);
  TEST_ASSERT_EQUAL(&TCB, list->tail);
}

/*
 *          +----+
 *  head -->| #1 | --> NULL
 *          +----+
 *  tail -----^
 *
 */
void test_addPriorityLinkedList_given_list_with_1_element_should_add_to_front(void){
  TCB *result;
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCB = {.next = NULL, .priority = 20};
  
  list->head = NULL;
  list->tail = NULL;
  
  addPriorityLinkedList(list, &TCB, compare);
  
  TEST_ASSERT_EQUAL(&TCB, list->head);
  TEST_ASSERT_EQUAL(&TCB, list->tail);
}