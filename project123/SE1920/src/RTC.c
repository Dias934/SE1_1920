#include "RTC.h"

void RTC_Init(time_t seconds){
	struct tm *info;
	info = localtime(&seconds);
	RTC_SetValue(info);
}
void RTC_GetValue(struct tm *dateTime){
	dateTime->tm_sec=(LPC_RTC->CTIME0&0x3f);
	dateTime->tm_min=(LPC_RTC->CTIME0&(0x3f<<8)>>8);
	dateTime->tm_hour=(LPC_RTC->CTIME0&(0x1f<<16)>>16);
	dateTime->tm_wday=(LPC_RTC->CTIME0&(0x7<<24)>>24);
	dateTime->tm_mday=(LPC_RTC->CTIME1&0x1f);
	dateTime->tm_mon=(LPC_RTC->CTIME1&(0xf<<8)>>8);
	dateTime->tm_year=(LPC_RTC->CTIME1&(0xfff<<16)>>16);
	dateTime->tm_yday=(LPC_RTC->CTIME2&0xfff);
}
void RTC_SetValue(struct tm *dateTime){
	   LPC_RTC->CCR=0x12;
	   LPC_RTC->SEC=dateTime->tm_sec;
	   LPC_RTC->MIN=dateTime->tm_min;
	   LPC_RTC->HOUR=dateTime->tm_hour;
	   LPC_RTC->DOM=dateTime->tm_mday;
	   LPC_RTC->DOW=dateTime->tm_wday;
	   LPC_RTC->DOY=dateTime->tm_yday;
	   LPC_RTC->MONTH=dateTime->tm_mon;
	   LPC_RTC->YEAR=dateTime->tm_year;
	   LPC_RTC->CCR|=(1);
}
void RTC_SetSeconds(time_t seconds){
	RTC_Init(seconds);
}
time_t RTC_GetSeconds(void){
	struct tm dateTime;
	RTC_GetValue(&dateTime);
	return mktime(&dateTime);
}
