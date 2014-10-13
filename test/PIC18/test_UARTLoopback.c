#include "unity.h"
#include "UARTLoopback.h"
#include "mock_usart.h"

void setUp(void)
{}

void tearDown(void)
{}

void test_uartLoopbackSM_given_WAIT_DATA_should_stay_in_same_state(void){
	LoopbackState state = WAIT_DATA;
  
  DataRdyUSART_ExpectAndReturn(0);
  
  uartLoopbackSM(&state);
  
  TEST_ASSERT_EQUAL(WAIT_DATA, state);
}

void test_uartLoopbackSM_given_WAIT_DATA_and_byte_arrive_should_read_and_transition_to_WAIT_TO_TX(void){
	LoopbackState state = WAIT_DATA;
  
  DataRdyUSART_ExpectAndReturn(1);
  getcUSART_ExpectAndReturn(0x5a);
  
  uartLoopbackSM(&state);
  
  TEST_ASSERT_EQUAL(WAIT_TO_TX, state);
}

void test_uartLoopbackSM_given_WAIT_TO_TX_and_transmit_buffer_not_empty_should_(void){
	LoopbackState state = WAIT_TO_TX;
  
  BusyUSART_ExpectAndReturn(1);
  
  uartLoopbackSM(&state);
  
  TEST_ASSERT_EQUAL(WAIT_TO_TX, state);
}
