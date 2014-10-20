#include "unity.h"
#include "UARTLoopback.h"
#include "mock_usart.h"

void setUp(void)
{}

void tearDown(void)
{}

void test_uartLoopbackSM_given_WAIT_DATA_should_stay_in_same_state(void){
	LoopbackData data = {.state = WAIT_DATA, .dataByte = 0x00};
  
  DataRdyUSART_ExpectAndReturn(0);
  
  uartLoopbackSM(&data);
  
  TEST_ASSERT_EQUAL(WAIT_DATA, data.state);
}

void test_uartLoopbackSM_given_WAIT_DATA_and_byte_arrive_should_read_and_transition_to_WAIT_TO_TX(void){
	LoopbackData data = {.state = WAIT_DATA, .dataByte = 0x00};
  
  DataRdyUSART_ExpectAndReturn(1);
  getcUSART_ExpectAndReturn(0x5a);
  
  uartLoopbackSM(&data);
  
  TEST_ASSERT_EQUAL(WAIT_TO_TX, data.state);
  TEST_ASSERT_EQUAL(0x5a, data.dataByte);
}

void test_uartLoopbackSM_given_WAIT_TO_TX_and_transmit_buffer_not_empty_should_stay_in_same_state(void){
	LoopbackData data = {.state = WAIT_TO_TX, .dataByte = 0x00};
  
  BusyUSART_ExpectAndReturn(1);
  
  uartLoopbackSM(&data);
  
  TEST_ASSERT_EQUAL(WAIT_TO_TX, data.state);
}

void test_uartLoopbackSM_given_WAIT_TO_TX_and_transmit_buffer_empty_should_transmit_and_change_to_WAIT_DATA(void){
	LoopbackData data = {.state = WAIT_TO_TX, .dataByte = 0x00};
  
  BusyUSART_ExpectAndReturn(0);
  putcUSART_Expect(0x00);
  
  uartLoopbackSM(&data);
  
  TEST_ASSERT_EQUAL(WAIT_DATA, data.state);
}