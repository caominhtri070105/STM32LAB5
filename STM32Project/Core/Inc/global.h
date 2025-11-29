/*
 * global.h
 *
 *  Created on: Nov 27, 2025
 *      Author: tri
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "stdint.h"
#include "uart.h"

#define MAX_BUFFER_SIZE 30
#define TIMEOUT_MS      3000

#define UART_IDLE     0
#define UART_WAIT_OK  1
#define UART_RESEND   2


extern char uart_buffer[MAX_BUFFER_SIZE];
extern char last_packet[MAX_BUFFER_SIZE];

extern uint32_t last_send_time;

extern uint8_t command_buffer[MAX_BUFFER_SIZE];
extern uint8_t command_index;

extern uint8_t uart_command_flag;
extern uint8_t uart_rx_buffer;

extern int uartState;



#endif /* INC_GLOBAL_H_ */
