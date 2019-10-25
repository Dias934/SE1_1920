/*
 * data_storage.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef DATA_STORAGE_H_
#define DATA_STORAGE_H_

#include "calendar.h"
#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"
#include "rtc.h"

extern struct tm dateTime;

const int* s[]={&dateTime.tm_sec};


void init_data_st(int units);

void backup_dateTime();

void send_dateTime();

void get_RTC_dateTime(char *str);

void get_Time(char* str);

void get_Date(char* str);

void change_sec(int set);

void change_min(int set);

void change_hour(int set);

void change_day(int set);

void change_month(int set);

void change_year(int set);

#endif /* DATA_STORAGE_H_ */
