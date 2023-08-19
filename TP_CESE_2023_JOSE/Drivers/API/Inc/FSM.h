/*
 * FSM.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_FSM_H_
#define API_INC_FSM_H_

#include "stdint.h"
#include "stdbool.h"
#include "main.h"

typedef bool bool_t;

void FSM_init(void);
void FSM_update(void);
void SENSOR_TESTING_Handler(void);
void IDLE_Handler(void);
void READING_Handler(void);
void ERROR_STATE_Handler(void);


#endif /* API_INC_FSM_H_ */
