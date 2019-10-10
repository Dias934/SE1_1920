/*
 * menu.c
 *
 *  Created on: 09/10/2019
 *      Author: A38866
 */

#include "menu.h"
#include "ui.h"

uint32_t count;
int button_map;

uint32_t * init_menu(){
	return &normal_execution;
}

uint32_t * up_and_down_pressed(uint32_t* origen(), uint32_t *destiny(), uint32_t *led_state()){
	if(count==0)count=wait_elapsed(count);
	if(wait_elapsed(0)/250%2>0)turn_on_led();
	else turn_off_led();
	if(wait_elapsed(count)>TWO_SECONDS){
		count=0;
		while(button_map!=NOT_PRESSED){
			if(wait_elapsed(0)/100%2>0)turn_on_led();
			else turn_off_led();
			button_map=BUTTON_GetButtonsEvents();
		}
		led_state();
		return destiny;
	}
	return origen;
}

