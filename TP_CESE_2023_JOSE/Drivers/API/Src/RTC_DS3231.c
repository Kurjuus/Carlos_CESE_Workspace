/*
 * RTC_DS3231.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Carlos Mendoza
 */

#include "RTC_DS3231.h"

void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	uint8_t data[2];

	//Setting the seconds
	data[0] = RTC_ADDRESS_SECONDS;
	data[1] = 0x00 | (0x0F & seconds);

	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	//Setting the minutes
	data[0] = RTC_ADDRESS_MINUTES;
	//data[1] = 0x00 | (0x0F & minutes);
	//data[1] = 0x58;

	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	//Setting the hour
	data[0] = RTC_ADDRESS_HOUR;
	data[1] = 0x40 | (0x0F & hours);

	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	return;
}

void setAlarm(void)
{
	uint8_t data[2];

	data[0] = RTC_ADDRESS_ALARM2_MINUTES;
	data[1] = (1 << 7);
	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	data[0] = RTC_ADDRESS_ALARM2_HOURS;
	data[1] = (1 << 7);
	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	data[0] = RTC_ADDRESS_ALARM2_DAY;
	data[1] = (3 << 6);
	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	data[0] = RTC_ADDRESS_CONTROL;
	data[1] = (3 << 1);
	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);

	data[0] = RTC_ADDRESS_CONTROL_STATUS;
	data[1] = 0x00;
	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);
}

void resetAlarm(void)
{
	uint8_t ptrReg, data[2];
	ptrReg = RTC_ADDRESS_CONTROL_STATUS;
	i2cSendStringSize(DEVICE_RTC_ADDRESS, &ptrReg, 1);
	i2cReceiveString(DEVICE_RTC_ADDRESS,data,1);

	data[0] = RTC_ADDRESS_CONTROL_STATUS;
	data[1] = 0x00;
	i2cSendStringSize(DEVICE_RTC_ADDRESS, data, 2);
}
