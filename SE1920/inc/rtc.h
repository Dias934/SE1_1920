/*
 * rtc.h
 *
 *  Created on: 23/10/2019
 *      Author: A38866
 */

#ifndef RTC_H_
#define RTC_H_

#include "time.h"
#include "LPC17xx.h"

#define CTCRST_VAL 0
#define CCALEN_VAL 0x10
#define INIT_VAL_RTC CTCRST_VAL|CCALEN_VAL
#define CLKEN_ENABLE 1
#define CLKEN_DISABLE 0



#define SEC_POSITION 0
#define MIN_POSITION 8
#define HOUR_POSITION 16
#define DOW_POSITION 24


#define DOM_POSITION 0
#define MONTH_POSITION 8
#define YEAR_POSITION 16


#define DOY_POSITION 0


#define SEC_BITS 0x3F
#define MIN_BITS 0x3F
#define HOUR_BITS 0x1F
#define DOW_BITS 0xF


#define DOM_BITS 0x1F
#define MONTH_BITS 0xF
#define YEAR_BITS 0xFFF


#define DOY_BITS 0xFFF

enum RTC_FLAGS {
		SEC_MASK=1,
		MIN_MASK,
		HOUR_MASK,
		DOW_MASK,
		DOM_MASK,
		MONTH_MASK,
		YEAR_MASK,
		DOY_MASK
};

#define TIME_MASK HOUR_MASK | MIN_MASK
#define DATE_MASK YEAR_MASK | MONTH_MASK | DOM_MASK



#define MAX_YEAR 4096
#define MAX_MONTH 12
#define MAX_DAY 31


#define MAX_SEC 60
#define MAX_MIN 60
#define MAX_HOUR 24


#define MONTH_ADJUSTMENT (+1) //LPC1769 [1-12] time.h [0-11]
#define DOY_ADJUSTMENT (+1) //LPC1769 [1-365(366)] time.h [0-365]

#define GMT_PLUS_ONE (+1)

void init_RTC(time_t seconds);

void RTC_GetValue(struct tm *dateTime);

void RTC_SetMaskedValue(struct tm *dateTime, short mask);

void RTC_SetValue(struct tm *dateTime);

void RTC_SetSconds(time_t seconds);

time_t RTC_GetSeconds(void);


#endif /* RTC_H_ */
