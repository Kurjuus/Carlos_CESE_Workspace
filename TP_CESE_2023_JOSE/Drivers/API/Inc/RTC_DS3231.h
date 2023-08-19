/*
 * RTC_DS3231.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_RTC_DS3231_H_
#define API_INC_RTC_DS3231_H_

#include "stdint.h"
#include "stdbool.h"
#include "stddef.h"
#include "stm32f4xx_hal.h"
#include "API_i2c.h"
#include "API_lcd.h"

// peripheral i2c address
#define DEVICE_RTC_ADDRESS	0xD0

// register address
#define RTC_ADDRESS_SECONDS 		0x00
#define RTC_ADDRESS_MINUTES			0x01
#define RTC_ADDRESS_HOUR			0x02
#define	RTC_ADDRESS_ALARM2_MINUTES	0x0B
#define	RTC_ADDRESS_ALARM2_HOURS	0x0C
#define	RTC_ADDRESS_ALARM2_DAY		0x0D
#define	RTC_ADDRESS_CONTROL			0x0E
#define	RTC_ADDRESS_CONTROL_STATUS	0x0F



typedef bool bool_t;

void setAlarm(void);
void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
void resetAlarm(void);

#endif /* API_INC_RTC_DS3231_H_ */
