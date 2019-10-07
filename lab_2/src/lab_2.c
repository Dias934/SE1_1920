/*
===============================================================================
 Name        : lab_2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <ui.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
void blink_led(int times, int millis, int millis_off);
void test1();
void test2();
int main(void) {
	init_ui();
	//test1();
	test2();

    return 0 ;
}

void blink_led_button_state(int val){
	val&=3;
	if(val==NOT_PRESSED)blink_led(1,100,400);
	if(val==PRESSED)blink_led(2,100,400);
	if(val==PRESSING)blink_led(50,10,400);
	if(val==RELEASED)blink_led(3,100,400);
}

void test2(){
	int but=0;
	while(1) {
		but=BUTTON_GetButtonsEvents();
		for(int i=0; i<3; i++){
			blink_led_button_state(but>>(2*i));
		}
	}
}

void test1(){
	uint32_t but=0;
	while(1) {
		but=BUTTON_Read();
	   	if(but==UP_BUTTON_MASK)blink_led(1,100,400);
	   	if(but==DOWN_BUTTON_MASK)blink_led(2,100,400);
	   	if(but==ENTER_BUTTON_MASK)blink_led(3,100,400);
	}
}

void blink_led(int times, int millis, int millis_off){
	while(times-->0){
		turn_on_led();
		wait_ms(millis);
		turn_off_led();
		wait_ms(millis);
	}
	wait_ms(millis_off);
}
