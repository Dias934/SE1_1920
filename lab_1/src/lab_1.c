/*
===============================================================================
 Name        : lab_1.c
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

#include <stdio.h>
#include "waiter.h"
#include "gpio_g1.h"
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define WAIT_TIME 60

int main(void) {

    //printf("Hello World\n");
	init_led2();
	wait_init();
    // Force the counter to be placed into memory
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	turn_on_led2();
    	wait_hz(WAIT_TIME);
    	turn_off_led2();
    	wait_hz(WAIT_TIME);
    }
    return 0 ;
}
