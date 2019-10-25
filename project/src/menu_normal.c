/*
 * menu_normal.c
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */

#include "menu_normal.h"
#include "menu_maintenance.h"

void view_normal(){
	//char str[16];
	get_RTC_dateTime(str);
	LCDText_Locate(0,0);
	LCDText_WriteString(str);
	//LCDText_Locate(1,0);
	//get_Temperature(str);
	//LCDText_WriteString(str);
}

uint32_t * normal_execution(){
	turn_off_led();
	view_normal();
	button_map=BUTTON_GetButtonsEvents();
	if(((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)) //checks if the up and down button are on the state pressed/pressing (the first bit is 1 if its pressed/pressing, check states)
		return up_and_down_pressed(&normal_execution, &maintenance_execution, &turn_on_led);
	else{
		turn_off_led();
		count=0;
	}
	return &normal_execution;
}
