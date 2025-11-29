/*
 * global.c
 *
 *  Created on: Nov 27, 2025
 *      Author: tri
 */

#include "global.h"

char uart_buffer[MAX_BUFFER_SIZE];
char last_packet[MAX_BUFFER_SIZE];

uint32_t last_send_time;

uint8_t command_buffer[MAX_BUFFER_SIZE];
uint8_t command_index = 0;

uint8_t uart_command_flag = 0;
uint8_t uart_rx_buffer;

int uartState = UART_IDLE;
