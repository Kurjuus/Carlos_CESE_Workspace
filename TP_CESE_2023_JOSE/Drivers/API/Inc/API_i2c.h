/*
 * API_i2c.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_API_I2C_H_
#define API_INC_API_I2C_H_

#include "stdint.h"
#include "stdbool.h"
#include <string.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

typedef bool bool_t;

void initI2CPort(void);
bool_t i2cInit();
void i2cSendString(uint16_t DeviceAddr, uint8_t *pData);
void i2cSendStringSize(uint16_t DeviceAddr, uint8_t *pData, uint32_t size);
void i2cReceiveString(uint16_t DeviceAddr, uint8_t *pData, uint32_t size);
void ErrorHandlerUser(void);


#endif /* API_INC_API_I2C_H_ */
