/*
 * ui.c
 *
 *  Created on: 01/10/2019
 *      Author: A38866
 */

#include <ui.h>


void init_ui(void){
	init_led();
	wait_init();
	BUTTON_Init();
}
