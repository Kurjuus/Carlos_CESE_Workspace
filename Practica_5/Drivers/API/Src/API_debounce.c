/*
 * API_debounce.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Carlos Mendoza
 */
#include "API_delay.h"
#include "API_debounce.h"
#include "API_uart.h"

#define PRESSED		1
#define RELEASED	0
#define DURATION_DELAY		40

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RISING
}debounceState_t;

static debounceState_t actualState;
static delay_t debounceDelay;
static bool_t fallingEdge;

void debounceFSM_init(void)
{
	actualState = BUTTON_UP;
	tick_t delayFSM = DURATION_DELAY;
	delayInit(&debounceDelay, delayFSM);
}

void debounceFSM_update(void)
{
	switch(actualState){
		case BUTTON_UP:
			if(PRESSED == HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13))
				actualState = BUTTON_FALLING;
			break;
		case BUTTON_FALLING:
			if(delayRead(&debounceDelay))
			{
				if(PRESSED == HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)){
					//fallingEdge = true;
					actualState = BUTTON_DOWN;
					buttonPressed();
				}
			}
			else
				actualState = BUTTON_UP;
			break;
		case BUTTON_DOWN:
			if(RELEASED == HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13))
				actualState = BUTTON_RISING;
			break;
		case BUTTON_RISING:
			if(delayRead(&debounceDelay))
			{

				if(RELEASED == HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)){
					//fallingEdge = false;
					actualState = BUTTON_UP;
					buttonReleased();
				}

			}
			else
				actualState = BUTTON_DOWN;
			break;
	}
}


bool_t readKey()
{
	bool_t tempValueKey = fallingEdge;
	if(fallingEdge == true)
	{
		fallingEdge = false;
	}
	return tempValueKey;
}

void buttonPressed(void)
{
	uint8_t Data[] = "BUTTON PRESSED\n\r";
	uint8_t *pData = Data;
	uartSendString(pData);
}

void buttonReleased(void)
{
	uint8_t Data[] = "BUTTON RELEASED\n\r";
	uint8_t *pData = Data;
	uartSendString(pData);
}
