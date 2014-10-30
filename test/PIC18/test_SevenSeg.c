#include "unity.h"
#include "SevenSeg.h"
#include "mock_spi.h"
#include "mock_Clock.h"
#include "p18f4520.h"

void setUp(void){}

void tearDown(void){}

void test_SevenSegSM_given_state_7Seg_INIT_should_reset_counter_and_record_clock_and_change_to_WAITING(void){
	SevenSegData data = {.state = _7Seg_INIT, .counter = 1, .currClock = 0};
	
	getClock_ExpectAndReturn(10);
	WriteSPI_ExpectAndReturn(0x77, 0x77);
	
	sevenSegSM(&data);
	
	TEST_ASSERT_EQUAL(_7Seg_WAITING, data.state);
	TEST_ASSERT_EQUAL(0, data.counter);
	TEST_ASSERT_EQUAL(10, data.currClock);
}

void test_SevenSegSM_given_state_7Seg_WAITING_no_OV_should_stay(void){
	SevenSegData data = {.state = _7Seg_WAITING, .counter = 0, .currClock = 0};
	
	getClock_ExpectAndReturn(100);
	
	sevenSegSM(&data);
	
	TEST_ASSERT_EQUAL(_7Seg_WAITING, data.state);
	TEST_ASSERT_EQUAL(0, data.counter);
	TEST_ASSERT_EQUAL(0, data.currClock);
}

void test_SevenSegSM_given_state_7Seg_WAITING_with_OV_should_increment_counter_and_stay(void){
	SevenSegData data = {.state = _7Seg_WAITING, .counter = 1, .currClock = 0};
	
	getClock_ExpectAndReturn(500);
	getClock_ExpectAndReturn(500);
	WriteSPI_ExpectAndReturn(0x14, 0x14);
	
	sevenSegSM(&data);
	
	TEST_ASSERT_EQUAL(_7Seg_WAITING, data.state);
	TEST_ASSERT_EQUAL(2, data.counter);
	TEST_ASSERT_EQUAL(500, data.currClock);
}
