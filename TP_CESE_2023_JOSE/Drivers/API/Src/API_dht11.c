/*
 * API_dht11.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Carlos Mendoza
 */

#include "API_dht11.h"

uint32_t data = 0;

/*
 * This indicates which port and what pin is used to read the data of sensor
 */

void DHT_Init_Port(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;//  GPIO PULL UP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
}

/*
 * This function verify if sensor is connected and if it is responding
 */

bool_t DHT_Response(void)
{
	bool_t response = false;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_Delay(18);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	delay_us(20);
	if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8))
		response = true;

	return response;
}



void DTH_Read(uint8_t *data)
{
	uint8_t j,k;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_Delay(18);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);

	delay_us(20);


	while(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8));
	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8));

	for(k=0; k<5; k++)
	{
		for(j = 0; j<8; j++)
		{
			while(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)));
			delay_us(40);
			if(!(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)))
			{
				data[k]&= ~(1<<(7-j));
			}
			else data[k]|= (1<<(7-j));
			while((HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)));
		}
	}

}
