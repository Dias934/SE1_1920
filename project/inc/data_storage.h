/*
 * data_storage.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef DATA_STORAGE_H_
#define DATA_STORAGE_H_

#include "stdio.h"
#include "peripherals.h"
#include "BMP280.h"
#include "flash.h"

#define TIME_FIELDS 2 //number of fields the user can change in the structure of time (HH:mm)
#define DATE_FIELDS 3 //number of fields the user can change in the structure of date (DD/MM/YYYY)
#define TEMP_FIELDS 0

#define YEAR_OFFSET 0
#define MONTH_OFFSET 0
#define DAY_OFFSET 1


enum MAX_DAYS_IN_MONTH {
	JANUARY_DAYS = 31,
	FEBRUARY_DAYS = 28,
	MARCH_DAYS = 31,
	APRIL_DAYS = 30,
	MAY_DAYS = 31,
	JUNE_DAYS = 30,
	JULY_DAYS = 31,
	AUGUST_DAYS = 31,
	SEPTEMBER_DAYS = 30,
	OCTOBER_DAYS = 31,
	NOVEMBER_DAYS = 30,
	DECEMBER_DAYS = 31
};

static const enum MAX_DAYS_IN_MONTH MAX_DAYS_MAP[] ={
		JANUARY_DAYS,
		FEBRUARY_DAYS,
		MARCH_DAYS,
		APRIL_DAYS,
		MAY_DAYS,
		JUNE_DAYS,
		JULY_DAYS,
		AUGUST_DAYS,
		SEPTEMBER_DAYS,
		OCTOBER_DAYS,
		NOVEMBER_DAYS,
		DECEMBER_DAYS
};

enum MONTH{
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

enum TEMPERATURE_UNITS{
	CELSIUS=0,
	FAHRENHEIT
};



void init_data_st();

void backup_dateTime();

void send_time();

void send_date();

void send_temp_unit();

void send_dateTime(short mask);

void dateTimeToString(char *str);

void TemperatureAndPressureToString(char *str);

void get_Time(char* str);

void get_Temperature(char *str);

void get_Date(char* str);

void change_time(int val);

void change_date(int val);

void change_temp_unit(int val);

int nextField(int type);

int get_CurrentField();

#endif /* DATA_STORAGE_H_ */
