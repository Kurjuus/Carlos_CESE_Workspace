/*
 * API_uart.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "stdint.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"

typedef bool bool_t;

bool_t uartInit();
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);
void Error_Handler_User(void);


#endif /* API_INC_API_UART_H_ */
