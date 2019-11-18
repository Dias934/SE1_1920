/*
 * data_storage.c
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#include "data_storage.h"

struct tm dateTime;

const char SEC_CHARACTER[2]={' ',':'};

int* TIME_PTRS[TIME_FIELDS]={&(dateTime.tm_hour),&(dateTime.tm_min)};
const int MAX_TIMES[TIME_FIELDS]={MAX_HOUR, MAX_MIN};

int* DATE_PTRS[DATE_FIELDS]={&(dateTime.tm_year),&(dateTime.tm_mon),&(dateTime.tm_mday)};
int MAX_DATES[DATE_FIELDS]={MAX_YEAR, MAX_MONTH, MAX_DAY};
int DATE_OFFSETS[DATE_FIELDS]={YEAR_OFFSET, MONTH_OFFSET, DAY_OFFSET};

short fieldToChange;

void init_data_st(int units){
	fieldToChange=0;
	RTC_GetValue(&dateTime);
}

void backup_dateTime(){
	fieldToChange=0;
	RTC_GetValue(&dateTime);
}

void send_time(){
	send_dateTime(TIME_MASK);
}

void send_date(){
	send_dateTime(DATE_MASK);
}

void send_dateTime(short mask){
	fieldToChange=0;
	RTC_SetMaskedValue(&dateTime,mask);
}

void dateTimeToString(char *str){
	RTC_GetValue(&dateTime);
	sprintf(str,"%02d/%02d/%04d %02d%c%02d",dateTime.tm_mday,dateTime.tm_mon+1, dateTime.tm_year+1900, dateTime.tm_hour,SEC_CHARACTER[dateTime.tm_sec%2],dateTime.tm_min);
}

void get_Time(char* str){
	sprintf(str,"%02d:%02d", dateTime.tm_hour, dateTime.tm_min);
}

void get_Date(char* str){
	sprintf(str,"%02d/%02d/%04d", dateTime.tm_mday,dateTime.tm_mon+1, dateTime.tm_year+1900);
}

void change_time(int val){
	(*TIME_PTRS[fieldToChange])+=val;
	if((*TIME_PTRS[fieldToChange])<0)(*TIME_PTRS[fieldToChange])=MAX_TIMES[fieldToChange]-1;
	(*TIME_PTRS[fieldToChange])=(*TIME_PTRS[fieldToChange])%MAX_TIMES[fieldToChange];
}

void change_date(int val){
	(*DATE_PTRS[fieldToChange])+=val;
	int max=MAX_DATES[fieldToChange];
	if(fieldToChange==2)
		max=MAX_DAYS_MAP[dateTime.tm_mon]+ (dateTime.tm_mon==FEBRUARY && ((dateTime.tm_year%4==0 && dateTime.tm_year%100!=0) || dateTime.tm_year%400==0)?1:0); //definir o valor máximo de dias.
	if((*DATE_PTRS[fieldToChange])<DATE_OFFSETS[fieldToChange])
		(*DATE_PTRS[fieldToChange])=max-1;
	(*DATE_PTRS[fieldToChange])=(*DATE_PTRS[fieldToChange])%max+DATE_OFFSETS[fieldToChange];
}

int nextField(int type){
	return type-(++fieldToChange);
}
