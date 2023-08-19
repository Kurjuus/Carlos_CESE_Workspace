/*
 * API_dht11.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_API_DHT11_H_
#define API_INC_API_DHT11_H_

#include "stdint.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include "API_timer1.h"

typedef bool bool_t;

void DHT_Init_Port(void);
void DTH_Read(uint8_t *data);
bool_t DHT_Response(void);


#endif /* API_INC_API_DHT11_H_ */
