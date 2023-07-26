/*
 * API_delay.c
 *
 *  Created on: Jul 6, 2023
 *      Author: kjtn
 */
#include "API_delay.h"

void delayInit(delay_t *delay, tick_t duration)
{
	//TODO: include asserts for parameters

	delay->running = false;
	delay->duration = duration;
}

bool_t delayRead(delay_t *delay)
{
	if(!delay->running)
	{
		delay->running = true;
		delay->startTime = HAL_GetTick();
	}
	else
	{
		if((HAL_GetTick() - delay->startTime) >= delay->duration)
		{
			delay->running = false;
			return true;
		}
	}
	return false;
}

void delayWrite(delay_t *delay, tick_t duration)
{
	delay->duration = duration;
	delay->startTime = HAL_GetTick();
}

