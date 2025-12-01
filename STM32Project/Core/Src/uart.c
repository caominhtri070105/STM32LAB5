/*
 * uart.c
 *
 *  Created on: Nov 27, 2025
 *      Author: tri
 */

#include "uart.h"
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart->Instance == USART2){
        HAL_UART_Transmit(&huart2, &uart_rx_buffer, 1, 10);
		if(uart_rx_buffer == '\n' || uart_rx_buffer == '\r'){
			command_buffer[command_index]= '\0';
			uart_command_flag=1;
			command_index=0;
		}else{
			if (command_index<MAX_BUFFER_SIZE -1){
				command_buffer[command_index++]=uart_rx_buffer;
			}
		}
		HAL_UART_Receive_IT(&huart2, &uart_rx_buffer, 1);
	}
}
