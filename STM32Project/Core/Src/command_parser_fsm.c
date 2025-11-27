/*
 * command_parser.c
 *
 *  Created on: Nov 24, 2025
 *      Author: tri
 */

#define MAX_BUFFER_SIZE 30

#include <command_parser_fsm.h>
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
        buffer[index_buffer++] = temp;
        if (index_buffer == MAX_BUFFER_SIZE){
        	index_buffer = 0;
        	buffer_flag = 1;
    }
}

void command_parser_fsm(char *command){
	if (strstr(command, "!RST#") != NULL){
		HAL_ADC_Start(&hadc1);
		if (HAL_ADC_PollForConversion(&hadc1,10)==HAL_OK){
			uint32_t ADC_Value=HAL_ADC_GetValue(&hadc1);
			sprintf(temp, "ADC=%lu#\r\n",ADC_Value);
			HAL_UART_Transmit(&huart2,(void *)str ,sprintf(tr,"%d\n",ADC_value), 1000) ;
			uartState=UART_WAIT_OK;
			last_send_time=HAL_GetTick();
		}
		HAL_ADC_Stop(&hadc1);
	}
	else if(strstr(command, "!OK#")!=NULL){
		uartState=UART_IDLE;
		HAL_UART_Transmit(&huart2, (uint8_t *)"Communication Ended\r\n", 22, 100);
	}
}

