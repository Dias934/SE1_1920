/*
 * calendar.c
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#include "calendar.h"
#include "stdlib.h"

Calendar_Typedef cal;

void init_cal(){
	cal.day=MIN_DAY;
	cal.month=MIN_MONTH;
	cal.year=MIN_YEAR;
}

void set_Day(short day){cal.day=day;}
void set_Month(short month){cal.month=month;}
void set_Year(short year){cal.year=year;}
short get_Day(){return cal.day;}
short get_Month(){return cal.month;}
short get_Year(){return cal.year;}

short set_Date(short day, short month, short year){
	if(year<MIN_YEAR) return ERROR_YEAR;
	if(month>MAX_MONTH || month<MIN_MONTH) return ERROR_MONTH;
	if(month==FEBRUARY){
		if((year%4==0 && year%100!=0)|| year%400==0){
			if(day>FEBRUARY_DAYS+1) return ERROR_DAY;
		}
		else if(day>FEBRUARY_DAYS) return ERROR_DAY;
	}
	else if(day>MAX_MAP[month]) return ERROR_DAY;
	set_Day(day);
	set_Month(month);
	set_Year(year);
	return SUCCESS;
}

