/*
 * uart_communication.c
 *
 *  Created on: Nov 25, 2025
 *      Author: tri
 */


#include "uart_communication.h"

void uart_communication_fsm(){
	switch(uartState){
	case UART_IDLE:
		break;
	case UART_WAIT_OK:
		if (timer1_flag==1){
			uartState=UART_RESEND;
		}
		break;
	case UART_RESEND:
		HAL_UART_Transmit(&huart2, (uint8_t *)last_packet, strlen(last_packet), 100);
		setTimer1(3000);
		uartState=UART_WAIT_OK;
		break;
	default:
		uartState=UART_IDLE;
		break;
	}
}
