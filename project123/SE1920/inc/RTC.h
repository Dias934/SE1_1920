#ifndef RTC_H_
#define RTC_H_


#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include "time.h"
#include "HD44780.h"



void RTC_Init(time_t seconds);
void RTC_GetValue(struct tm *dateTime);
void RTC_SetValue(struct tm *dateTime);
void RTC_SetSeconds(time_t seconds);
time_t RTC_GetSeconds(void);

#endif /* RTC_H_ */
