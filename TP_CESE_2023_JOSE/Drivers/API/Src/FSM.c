/*
 * FSM.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Carlos Mendoza
 */

#include "FSM.h"
#include "API_i2c.h"
#include "API_lcd.h"
#include "RTC_DS3231.h"
#include "API_dht11.h"
#include "API_timer1.h"
#include "API_delay.h"
#include <stdio.h>

#define DELAY_TICK 			2000
#define DELAY_READING		5000
#define GOOD				true
#define FAIL				false
#define LED_DISCONNECTED 	GPIO_PIN_11
#define LED_CONNECTED		GPIO_PIN_10

typedef enum{
	SENSOR_TESTING,
	IDLE,
	READING,
	ERROR_STATE
}fsmState_t;

static fsmState_t actualState;
static bool_t statusSensor;

delay_t delay, delayReading;
tick_t delaytick = DELAY_TICK, delayReadtick = DELAY_READING;

void FSM_init(void)
{
	initI2CPort();
	i2cInit();
	lcd_init();
	DHT_Init_Port();
	TimerInit();
	startTimer1();
	setTime(0,0,0);
	setAlarm();

	lcdClear();
	lcdPutCur(1, 3);
	lcdSendString("Initializing...");

	delayInit(&delay, delaytick);
	delayInit(&delay, delayReadtick);

	actualState = SENSOR_TESTING;

}

void FSM_update(void)
{
	switch(actualState)
	{
		case SENSOR_TESTING:
			SENSOR_TESTING_Handler();
			if(delayRead(&delay))
			{
				IDLE_Handler();
				actualState = IDLE;
			}
			break;
		case IDLE:
			if(( !HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12) ) && ( statusSensor == GOOD ) )
			{
				READING_Handler();
				actualState = READING;
			}else if(statusSensor ==  FAIL)
			{
				actualState = ERROR_STATE;
			}
			break;
		case READING:
			if(delayRead(&delayReading))
			{
				IDLE_Handler();
				actualState = IDLE;
			}
			break;
		case ERROR_STATE:
			ERROR_STATE_Handler();
			actualState = SENSOR_TESTING;
			break;
		default:
			break;
	}
}

/****************************************************************
 ******************Handler functions of FSM**********************
 ****************************************************************/

void SENSOR_TESTING_Handler(void)
{
	char message[] = "   SENSOR TESTING";
	lcdClear();
	lcdPutCur(0, 0);
	lcdSendString(message);
	if(DHT_Response())
	{
		HAL_GPIO_WritePin(GPIOC, LED_DISCONNECTED, RESET);
		HAL_GPIO_WritePin(GPIOC, LED_CONNECTED, SET);
		lcdPutCur(2, 5);
		lcdSendString("Ok!");
		statusSensor = GOOD;
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, LED_CONNECTED, RESET);
		HAL_GPIO_WritePin(GPIOC, LED_DISCONNECTED, SET);
		lcdPutCur(2, 5);
		lcdSendString("Fail!");
		statusSensor = FAIL;
	}
}

void IDLE_Handler(void)
{
	char message[] = "IDLE";
	lcdClear();
	lcdPutCur(1, 8);
	lcdSendString(message);
}

void READING_Handler(void)
{
	uint8_t dht11_data[5];
	if(DHT_Response())
	{
		HAL_Delay(2000);
		char message[] = "READING";
		lcdClear();
		lcdPutCur(0, 6);
		lcdSendString(message);

		DTH_Read(dht11_data);

		char temp[20];
		sprintf(temp,"Temp = %u", dht11_data[2]);
		lcdPutCur(2, 3);
		lcdSendString(temp);
		resetAlarm();
		HAL_Delay(2000);
	}else
	{
		statusSensor = FAIL;
	}
}

void ERROR_STATE_Handler(void)
{
	if(statusSensor == FAIL)
	{
		lcdClear();
		lcdPutCur(1, 0);
		lcdSendString("SENSOR DISCONNECTED.");
	}else
	{
		lcdClear();
		lcdPutCur(1, 0);
		lcdSendString("SOME ERRORS OCCURS...");
		lcdPutCur(2, 0);
		lcdSendString("YOU NEED TO RESET");
		lcdPutCur(3, 6);
		lcdSendString("SYSTEM");
	}
}
