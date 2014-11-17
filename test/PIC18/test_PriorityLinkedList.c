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

/*          NEW ELE
 *          +----+
 *  head -->| #1 | --> NULL
 *          +----+
 *  tail -----^
 *
 */
void test_addPriorityLinkedList_should_add_to_empty_list(void){
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCBnew = {.next = NULL, .priority = 20};
  
  list->head = NULL;
  list->tail = NULL;
  
  addPriorityLinkedList(list, &TCBnew, compare);
  
  TEST_ASSERT_EQUAL(&TCBnew, list->head);
  TEST_ASSERT_EQUAL(&TCBnew, list->tail);
}

/*                     NEW ELE
 *          +----+     +----+
 *  head -->| #1 | --> | #2 | --> NULL
 *          +----+     +----+
 *  tail ----------------^
 *
 */
void test_addPriorityLinkedList_should_add_to_list_with_one_element_at_back(void){
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCBdata = {.next = NULL, .priority = 20};
  TCB TCBnew = {.next = NULL, .priority = 10};
  
  list->head = &TCBdata;
  list->tail = &TCBdata;
  
  addPriorityLinkedList(list, &TCBnew, compare);
  
  TEST_ASSERT_EQUAL(&TCBdata, list->head);
  TEST_ASSERT_EQUAL(&TCBnew, list->tail);
  TEST_ASSERT_EQUAL(&TCBnew, TCBdata.next);
}

/*          NEW ELE
 *          +----+     +----+
 *  head -->| #2 | --> | #1 | --> NULL
 *          +----+     +----+
 *  tail ----------------^
 *
 */
void test_addPriorityLinkedList_should_add_to_list_with_one_element_at_front(void){
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCBdata = {.next = NULL, .priority = 20};
  TCB TCBnew = {.next = NULL, .priority = 30};
  
  list->head = &TCBdata;
  list->tail = &TCBdata;
  
  addPriorityLinkedList(list, &TCBnew, compare);
  
  TEST_ASSERT_EQUAL(&TCBnew, list->head);
  TEST_ASSERT_EQUAL(&TCBdata, list->tail);
  TEST_ASSERT_EQUAL(&TCBdata, TCBnew.next);
}

/*                    NEW ELE
 *          +----+     +----+     +----+
 *  head -->| #1 | --> | #3 | --> | #2 | --> NULL
 *          +----+     +----+     +----+
 *  tail ---------------------------^
 *
 */
void test_addPriorityLinkedList_should_add_to_list_with_2_element_in_between(void){
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCB2data = {.next = NULL, .priority = 20};
  TCB TCBdata = {.next = &TCB2data, .priority = 40};
  TCB TCBnew = {.next = NULL, .priority = 30};
  
  list->head = &TCBdata;
  list->tail = &TCB2data;
  
  addPriorityLinkedList(list, &TCBnew, compare);
  
  TEST_ASSERT_EQUAL(&TCBdata, list->head);
  TEST_ASSERT_EQUAL(&TCB2data, list->tail);
  TEST_ASSERT_EQUAL(&TCBnew, TCBdata.next);
  TEST_ASSERT_EQUAL(&TCB2data, TCBnew.next);
}

/*                                NEW ELE
 *          +----+     +----+     +----+     +----+
 *  head -->| #1 | --> | #2 | --> | #4 | --> | #3 | --> NULL
 *          +----+     +----+     +----+     +----+
 *  tail --------------------------------------^
 *
 */
void test_addPriorityLinkedList_should_add_to_list_with_3_element_in_between(void){
	PriorityLinkedList *list;
  list = createPriorityLinkedList();
  TCB TCB3data = {.next = NULL, .priority = 10};
  TCB TCB2data = {.next = &TCB3data, .priority = 30};
  TCB TCBdata = {.next = &TCB2data, .priority = 40};
  TCB TCBnew = {.next = NULL, .priority = 20};
  
  list->head = &TCBdata;
  list->tail = &TCB3data;
  
  addPriorityLinkedList(list, &TCBnew, compare);
  
  TEST_ASSERT_EQUAL(&TCBdata, list->head);
  TEST_ASSERT_EQUAL(&TCB3data, list->tail);
  TEST_ASSERT_EQUAL(&TCBnew, TCB2data.next);
  TEST_ASSERT_EQUAL(&TCB3data, TCBnew.next);
}