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
		if (HAL_GetTick()-last_send_time > TIMEOUT_MS){
			uartState=UART_RESEND;
		}
		break;
	case UART_RESEND:
		HAL_UART_Transmit(&huart2, (uint8_t *)last_packet, strlen(last_packet), 100);
		last_send_time=HAL_GetTick();
		uartState=UART_WAIT_OK;
		break;
	default:
		uartState=UART_IDLE;
		break;
	}
}
