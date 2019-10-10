/*
 * menu_maintenance.h
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */
#include "menu_maintenance.h"

uint32_t count_10;

uint32_t * maintenance_execution(){

	button_map=BUTTON_GetButtonsEvents();
	if(((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){ //checks if the up and down button are on the state pressed/pressing
		return up_and_down_pressed(&maintenance_execution, &normal_execution, &turn_off_led);
	}
	else{
		turn_on_led();
		count=0;
	}
	if((((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0)){
		return &maintenance_execution; //change this to menu_change_field execution function later
	}
	if(!(((button_map&PRESSED)>0) || (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0) || (((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0))){
		if(count_10==0)count_10=wait_elapsed(count_10);
		if(wait_elapsed(count_10)>TEN_SECONDS){
			count_10=0;
			return &normal_execution;
		}
	}
	else count_10=0;
	return &maintenance_execution;
}
