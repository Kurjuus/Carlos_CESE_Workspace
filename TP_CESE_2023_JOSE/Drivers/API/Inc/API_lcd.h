/*
 * API_lcd.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_API_LCD_H_
#define API_INC_API_LCD_H_

#include "stdint.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"
#include "API_i2c.h"

void lcdSendCommand(char cmd);
void lcdSendData(char data);
void lcd_init(void);
void lcdSendString(char *string);
void lcdPutCur(int row, int col);
void lcdClear(void);

#endif /* API_INC_API_LCD_H_ */
