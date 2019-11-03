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
extern short fieldToChange;

#define TIME_FIELDS 2 //number of fields the user can change in the structure of time (HH:mm)
#define DATE_FIELDS 3 //number of fields the user can change in the structure of date (DD/MM/YYYY)
//const int* s[]={&dateTime.tm_sec};


void init_data_st(int units);

void backup_dateTime();

void send_time();

void send_date();

void send_dateTime(short mask);

void dateTimeToString(char *str);

void get_Time(char* str);

void get_Date(char* str);

int nextField(int type);

void change_sec(int set);

void change_min(int set);

void change_hour(int set);

void change_day(int set);

void change_month(int set);

void change_year(int set);

#endif /* DATA_STORAGE_H_ */
