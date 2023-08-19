/*
 * API_timer1.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Carlos Mendoza
 */

#include "API_timer1.h"

TIM_HandleTypeDef htim1;

/***********************************************************************************************
 ***********************************************************************************************
 ********************THIS LIBRARY IS USED TO HANDLE DELAYS IN MICRO SECONDS*********************
 *********THESE DELAYS ARE NEEDED TO HANDLE THE 1-WIRE COMMUNICATION WITH DHT11 SENSOR**********
 ***********************************************************************************************
 ***********************************************************************************************/


void TimerInit(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 168-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0xffff-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    ErrorHandlerUserT();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    ErrorHandlerUserT();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
	 ErrorHandlerUserT();
  }

}

/*
 * This is the function that produce the delay in microseconds
 */

void delay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // wait for the counter to reach the us input in the parameter
}

/*
 * Star the timer 1
 */

void startTimer1()
{
	HAL_TIM_Base_Start(&htim1);
}

void ErrorHandlerUserT()
{
	while(1);
}
