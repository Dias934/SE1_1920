/*
 * menu.c
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */

#include "menu.h"
#include "menu_normal.h"

uint32_t count;
int button_map;

void *init_menu(){
	init_peripherals();
	return &normal_execution;
}

void *up_and_down_pressed(void *origen(), void *destiny(), void *led_state()){
	if(count==0)
		count=wait_elapsed(count);
	if((wait_elapsed(0)/PRESSING_TIME)%2>0)
		turn_on_led();
	else
		turn_off_led();
	if(wait_elapsed(count)>=TWO_SECONDS){
		count=0;
		while(button_map!=NOT_PRESSED){
			if((wait_elapsed(0)/RELEASE_TIME)%2>0)turn_on_led();
			else turn_off_led();
			button_map=BUTTON_GetButtonsEvents();
		}
		led_state();
		LCDText_Clear();
		return destiny;
	}
	return origen;
}
