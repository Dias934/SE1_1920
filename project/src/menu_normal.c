/*
 * menu_normal.c
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */

#include "menu_normal.h"
#include <stdio.h>

uint32_t * normal_execution(){
	//update_lcd();
	turn_off_led();
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
			turn_on_led();
			return &maintenance_execution;
		}
	}
	else{
		turn_off_led();
		count_2s=0;
	}
	return &normal_execution;
}
