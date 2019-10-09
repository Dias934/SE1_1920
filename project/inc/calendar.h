/*
 * calendar.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <stdarg.h>

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

static const enum MAX_DAYS_IN_MONTH MAX_MAP[] ={
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
	JANUARY = 1,
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

enum SET_MESSAGES{
	SUCCESS,
	ERROR_DAY,
	ERROR_MONTH,
	ERROR_YEAR
};

#define MIN_DAY 1
#define MAX_DAY 31
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_YEAR 0

typedef struct{
	short day;
	short month;
	short year;
}Calendar_Typedef;

void init_cal();
short get_Day();
short get_Month();
short get_Year();

short set_Date(short day, short month, short year);

#endif /* CALENDAR_H_ */
