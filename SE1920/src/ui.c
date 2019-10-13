/*
 * ui.c
 *
 *  Created on: 01/10/2019
 *      Author: A38866
 */

#include <ui.h>


void init_ui(void){
	wait_init();
	LCDText_Init();
	init_led();
	BUTTON_Init();
}
