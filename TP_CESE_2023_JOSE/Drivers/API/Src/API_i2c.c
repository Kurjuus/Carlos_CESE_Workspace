/*
 * API_i2c.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Carlos Mendoza
 */

#include "API_i2c.h"

I2C_HandleTypeDef I2C_Handle;

void initI2CPort(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_PULLUP;//  GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

bool_t i2cInit()
{
	uint8_t state;
	I2C_Handle.Instance = I2C2;
	I2C_Handle.Init.ClockSpeed = 100000;
	I2C_Handle.Init.DutyCycle = I2C_DUTYCYCLE_2;
	I2C_Handle.Init.OwnAddress1 = 0;
	I2C_Handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	I2C_Handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2C_Handle.Init.OwnAddress2 = 0;
	I2C_Handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2C_Handle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	state = HAL_I2C_Init(&I2C_Handle);
	if(state != HAL_OK)
		ErrorHandlerUser();


	if (HAL_I2CEx_ConfigAnalogFilter(&I2C_Handle, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	  ErrorHandlerUser();

	if (HAL_I2CEx_ConfigDigitalFilter(&I2C_Handle, 0) != HAL_OK)
	  ErrorHandlerUser();

	return state;
}

void i2cSendString(uint16_t DeviceAddr, uint8_t *pData)
{
	uint16_t size = (strlen(( (char*)pData ) ));
	size--;
	HAL_I2C_Master_Transmit(&I2C_Handle, DeviceAddr, pData, size, 100);
}

void i2cSendStringSize(uint16_t DeviceAddr, uint8_t *pData, uint32_t size)
{
	HAL_I2C_Master_Transmit(&I2C_Handle, DeviceAddr, pData, size, 100);
}

void i2cReceiveString(uint16_t DeviceAddr, uint8_t *pData, uint32_t size)
{
	HAL_I2C_Master_Receive(&I2C_Handle, DeviceAddr, pData, size, 100);
}

void ErrorHandlerUser(void)
{

}
