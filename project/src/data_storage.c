/*
 * data_storage.c
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#include "data_storage.h"

struct tm dateTime;

const char SEC_CHARACTER[2]={' ',':'};
int* TIME_PTRS[2]={&(dateTime.tm_hour),&(dateTime.tm_min)};
const int MAX_TIMES[2]={24,60};
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

int nextField(int type){
	return type-(++fieldToChange);
}

void change_sec(int set){
	dateTime.tm_sec+=set;
}

void change_min(int set){
	dateTime.tm_min+=set;
}

void change_hour(int set){
	dateTime.tm_hour+=set;
}

void change_day(int set){
	dateTime.tm_mday+=set;
}

void change_month(int set){
	dateTime.tm_mon+=set;
}

void change_year(int set){
	dateTime.tm_year+=set;
}
