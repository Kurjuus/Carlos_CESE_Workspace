/*
 * API_lcd.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Carlos Mendoza
 */

#include "API_lcd.h"

#define SLAVE_ADDRESS_LCD	0x4E
#define BYTE_TO_SEND		4

extern I2C_HandleTypeDef I2C_Handle;

/*
 * This function send a command to the LCD by I2C protocol
 */

void lcdSendCommand(char cmd)
{
	char upperData, lowerData;
	uint8_t pData[4];
	upperData = (cmd & 0xF0);
	lowerData = ((cmd<<4) & 0xF0);
	pData[0] = upperData | 0x0C;
	pData[1] = upperData | 0x08;
	pData[2] = lowerData | 0x0C;
	pData[3] = lowerData | 0x08;
	i2cSendStringSize(SLAVE_ADDRESS_LCD, pData, BYTE_TO_SEND);
	//HAL_I2C_Master_Transmit(&I2C_Handle, SLAVE_ADDRESS_LCD, (uint8_t*)pData, 4, 100);
}

/*
 * This function send a character to the LCD by I2C protocol
 */

void lcdSendData(char data)
{
	char upperData, lowerData;
	uint8_t pData[4];
	upperData = (data & 0xF0);
	lowerData = ((data<<4) & 0xF0);
	pData[0] = upperData | 0x0D;
	pData[1] = upperData | 0x09;
	pData[2] = lowerData | 0x0D;
	pData[3] = lowerData | 0x09;
	i2cSendStringSize(SLAVE_ADDRESS_LCD, pData, BYTE_TO_SEND);
	//HAL_I2C_Master_Transmit(&I2C_Handle, SLAVE_ADDRESS_LCD, (uint8_t*)pData, 4, 100);
}

/*
 * This function initialize the LCD
 */

void lcd_init(void)
{
	// 4 bit initialisation
	HAL_Delay(50);  			// wait for >40ms
	lcdSendCommand (0x30);
	HAL_Delay(5);  				// wait for >4.1ms
	lcdSendCommand (0x30);
	HAL_Delay(1);  				// wait for >100us
	lcdSendCommand (0x30);
	HAL_Delay(10);
	lcdSendCommand (0x20);  	// 4bit mode
	HAL_Delay(10);

	lcdSendCommand (0x28); 		// Function set
	HAL_Delay(1);
	lcdSendCommand (0x08); 		//Display on/off control
	HAL_Delay(1);
	lcdSendCommand (0x01); 		// clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcdSendCommand (0x06); 		//Entry mode set
	HAL_Delay(1);
	lcdSendCommand (0x0C); 		//Display on/off control
}

void lcdSendString(char *string)
{
	while(*string)
		lcdSendData(*string++);
}

/*
 * This function is used to move through the screen of display
 */

void lcdPutCur(int row, int col)
{
	switch(row)
	{
		case 0:
			col |= (0x00 + col);
			break;
		case 1:
			col |= (0x40 + col);
			break;
		case 2:
			col |= (0x14 + col);
			break;
		case 3:
			col |= (0x54 + col);
			break;
	}

	lcdSendCommand(col | 0x80);
}

/*
 * This function clear the screen of display
 */

void lcdClear(void)
{
	lcdSendCommand(0x80);
	for(int i = 0; i < 70; i++)
		lcdSendData(' ');
}
