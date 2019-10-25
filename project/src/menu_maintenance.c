/*
 * menu_maintenance.h
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */
#include "menu_maintenance.h"
#include "menu_normal.h"
#include "menu_change_field.h"

uint32_t count_10;

uint32_t (*view[3])()={change_time_view,change_date_view,change_temperature_units_view};
uint32_t *change_field[3]={&change_time,&change_date,&change_temperature_units};

uint32_t idx=0;

uint32_t * maintenance_execution(){
	(*view[idx%3])();
	backup_dateTime();
	button_map=BUTTON_GetButtonsEvents();
	if(!(((button_map&PRESSED)>0) || (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0) || (((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0))){
				if(count_10==0)count_10=wait_elapsed(count_10);
				if(wait_elapsed(count_10)>TEN_SECONDS){
					count_10=0;
					turn_off_led();
					LCDText_Clear();
					return &normal_execution;
				}
	}
	else count_10=0;
	if(((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){ //checks if the up and down button are on the state pressed/pressing
		return up_and_down_pressed(&maintenance_execution, &normal_execution, &turn_off_led);
	}
	else{
		turn_on_led();
		count=0;
	}
	if(((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0){
		while(button_map!=NOT_PRESSED)
			button_map=BUTTON_GetButtonsEvents();
		LCDText_Cursor(1);
		return change_field[idx%3]; //change this to menu_change_field execution function later
	}
	if(((button_map&PRESSED)>0) && !(((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){
		if(!((button_map&PRESSING)==PRESSING)){
			idx++;
			LCDText_Clear();
		}
	}
	if(!((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){
		if(!((button_map>>DOWN_BUTTON_POSITION&PRESSING)==PRESSING)){
			LCDText_Clear();
			idx--;
		}
	}
	return &maintenance_execution; //checks if no button is pressed for 10 seconds to change to normal menu. If not returns maintenance menu
}
