/*
 * command_parser.c
 *
 *  Created on: Nov 24, 2025
 *      Author: tri
 */

#include "command_parser_fsm.h"
void command_parser_fsm(char *command){
	if (strstr(command, "!RST#")!=NULL){
		HAL_ADC_Start(&hadc1);
		if (HAL_ADC_PollForConversion(&hadc1, 10)== HAL_OK){
			uint32_t adc_value=HAL_ADC_GetValue(&hadc1);
			sprintf(last_packet,"!ADC=%lu#\r\n", adc_value);
			HAL_UART_Transmit(&huart2, (uint8_t *)last_packet, strlen(last_packet), 100);
			uartState=UART_WAIT_OK;
			last_send_time=HAL_GetTick();
		}
		HAL_ADC_Stop(&hadc1);
	} else if (strstr(command, "!OK#")!= NULL){
		uartState=UART_IDLE;
		HAL_UART_Transmit(&huart2, (uint8_t *)"Communication Ended\r\n", 22, 100);
	}else{
		HAL_UART_Transmit(&huart2,( uint8_t *)"Unknown Command\r\n", 18, 100);
	}
}
