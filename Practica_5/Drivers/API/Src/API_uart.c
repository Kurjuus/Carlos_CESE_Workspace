/*
 * API_uart.c
 *
 *  Created on: Jul 27, 2023
 *      Author: Carlos Mendoza
 */

#include "API_uart.h"
#define TIMEOUT	100
#define BIT		1

UART_HandleTypeDef huart_handle;

bool_t uartInit()
{
	uint8_t stateInit = 0;
	huart_handle.Instance = USART3;
	huart_handle.Init.BaudRate = 115200;
	huart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	huart_handle.Init.StopBits = UART_STOPBITS_1;
	huart_handle.Init.Parity = UART_PARITY_NONE;
	huart_handle.Init.Mode = UART_MODE_TX_RX;
	huart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart_handle.Init.OverSampling = UART_OVERSAMPLING_16;
	stateInit = HAL_UART_Init(&huart_handle);
	return stateInit;
}
void uartSendString(uint8_t * pstring)
{
	if(pstring)
	{
		uint16_t size = 0;
		for(int i = 0; pstring[i] != '\0'; i++)
			size++;
		HAL_UART_Transmit(&huart_handle,&pstring[0],size,TIMEOUT);
	}
	else
		Error_Handler_User();
}
void uartSendStringSize(uint8_t * pstring, uint16_t size)
{
	uint16_t sizeArray = 0;
	if(pstring)
	{
		for(int i = 0; pstring[i] != '\0'; i++)
			sizeArray++;
		if(size <= sizeArray)
		{
			for(int i = 0; i < size; i++)
			{
				HAL_UART_Transmit(&huart_handle,&pstring[i],BIT,TIMEOUT);
			}
		}
		else
			Error_Handler_User();
	}
	else
		Error_Handler_User();
}
void uartReceiveStringSize(uint8_t *pstring, uint16_t size)
{
	if(HAL_UART_Receive(&huart_handle, &pstring[0], size, TIMEOUT) != HAL_OK)
		Error_Handler_User();
}

void Error_Handler_User(void)
{
	while(1)
	{
	}
}
