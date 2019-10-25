
#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include <stdlib.h>
#include <cr_section_macros.h>
#include <ui.h>
#include <time.h>

int main(void) {
	init_ui();
	struct tm *temp;
	temp=malloc(sizeof(struct tm));
	RTC_GetValue(temp);
	while(1){
		LCDText_Locate(0,0);
		LCDText_Printf("%d/%d/%d %d:%d",temp->tm_mday,temp->tm_mon, temp->tm_year, temp->tm_hour, temp->tm_min);
		wait_ms(10000);
	}
	free(temp);
    return 0 ;
}
