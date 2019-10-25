/*
 * menu_change_field.c
 *
 *  Created on: 23/10/2019
 *      Author: A38866
 */


#include "menu_change_field.h"
#include "menu_maintenance.h"
#include "stdio.h"

short field=0;
uint32_t count_pressing_button=0;

void change_time_view(){
	LCDText_Locate(0,0);
	LCDText_WriteString("Change Time");
	LCDText_Locate(1,0);
	get_Time(str);
	LCDText_WriteString(str);
}

void change_date_view(){
	LCDText_Locate(0,0);
	LCDText_WriteString("Change Date");
	LCDText_Locate(1,0);
	get_Date(str);
	LCDText_WriteString(str);
}

void change_temperature_units_view(){
	LCDText_Locate(0,0);
	LCDText_WriteString("Change Temp. Un");
	//LCDText_Locate(1,0);
	//get_Time(str);
	//LCDText_WriteString(str);
}

uint32_t * change_time(){
	LCDText_Locate(1,1+field*3);
	button_map=BUTTON_GetButtonsEvents();
	if(!(((button_map&PRESSED)>0) || (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0) || (((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0))){
		if(count_10==0)count_10=wait_elapsed(count_10);
		if(wait_elapsed(count_10)>TEN_SECONDS){
			count_10=0;
			LCDText_Clear();
			backup_dateTime();
			LCDText_Cursor(0);
			return &maintenance_execution;
			}
	}
	else count_10=0;
	if(((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){ //checks if the up and down button are on the state pressed/pressing
		return up_and_down_pressed(&change_time, &maintenance_execution, &turn_on_led);
	}
	else{
		turn_on_led();
		count=0;
	}
	if(((button_map&PRESSED)>0) && !(((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){
		if(count_pressing_button==0)count_pressing_button=wait_elapsed(count_pressing_button);
		if(wait_elapsed(count_pressing_button)>100){
			change_Time(field,1);
			change_time_view();
			count_pressing_button=0;
		}
	}
	else if(!((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){
		if(count_pressing_button==0)count_pressing_button=wait_elapsed(count_pressing_button);
		if(wait_elapsed(count_pressing_button)>100){
			change_Time(field,-1);
			change_time_view();
			count_pressing_button=0;
		}
	}
	else
		count_pressing_button=0;
	if(((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0){
			while(button_map!=NOT_PRESSED)
				button_map=BUTTON_GetButtonsEvents();
			field++;
	}
	if(field==2){
		send_dateTime();
		LCDText_Clear();
		field=0;
		LCDText_Cursor(0);
		return &maintenance_execution;
	}
	return &change_time;
}

uint32_t * change_date(){
	return &maintenance_execution;
}

uint32_t * change_temperature_units(){
	return &maintenance_execution;
}
