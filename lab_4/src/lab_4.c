/*
 ===============================================================================
 Name        : lab_3.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "peripherals.h"
#include "stdlib.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
const char SEC_CHARACTER[2]={' ',':'};
int main(void) {
	int idx=0;
	init_peripherals();
	time_t rawtime;
	time(&rawtime);
	init_RTC(rawtime);
	struct tm *temp;
	temp=malloc(sizeof(struct tm));
	while (1) {
		RTC_GetValue(temp);
		LCDText_Locate(0,0);
		idx=(idx+RTC_SecInterrupt())%2;
		LCDText_Printf("%02d/%02d/%04d %02d%c%02d",temp->tm_mday,(temp->tm_mon)+1, (temp->tm_year)+1900, temp->tm_hour,SEC_CHARACTER[idx] , temp->tm_min);
		wait_ms(50);
	}
	return 0;
}

