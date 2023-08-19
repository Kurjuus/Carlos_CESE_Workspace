/*
 * API_timer1.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_API_TIMER1_H_
#define API_INC_API_TIMER1_H_

#include "stdint.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

void delay_us (uint16_t us);
void ErrorHandlerUserT(void);
void TimerInit(void);
void startTimer1(void);

#endif /* API_INC_API_TIMER1_H_ */
