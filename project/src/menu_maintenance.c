/*
 * menu_maintenance.h
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */
#include "menu_maintenance.h"


uint32_t count_10s;

uint32_t * maintenance_execution(){

	button_map=BUTTON_GetButtonsEvents();
	if(((button_map&PRESSED)>0) && (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0)){ //checks if the up and down button are on the state pressed/pressing (the first bit is 1 if its pressed/pressing, check states)
		if(count_2s==0)count_2s=wait_elapsed(count_2s);
		if(wait_elapsed(0)/250%2>0)turn_on_led();
		else turn_off_led();
		if(wait_elapsed(count_2s)>2000){
			count_2s=0;
			while(button_map!=NOT_PRESSED){
				if(wait_elapsed(0)/100%2>0)turn_on_led();
				else turn_off_led();
				button_map=BUTTON_GetButtonsEvents();
			}
			turn_off_led();
			return &normal_execution;
		}
	}
	else{
		turn_on_led();
		count_2s=0;
	}
	if((((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0)){
		return &maintenance_execution; //change this to menu_change_field execution function later
	}
	if(!(((button_map&PRESSED)>0) || (((button_map>>DOWN_BUTTON_POSITION)&PRESSED)>0) || (((button_map>>ENTER_BUTTON_POSITION)&PRESSED)>0))){
		if(count_10s==0)count_10s=wait_elapsed(count_10s);
		if(wait_elapsed(count_10s)>10000){
			count_10s=0;
			return &normal_execution;
		}
	}
	else count_10s=0;
	return &maintenance_execution;
}
