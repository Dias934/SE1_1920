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
#include "ui.h"
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define WAIT_TIME 500

int main(void) {

    //printf("Hello World\n");
	init_ui();
    // Force the counter to be placed into memory
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	turn_on_led();
    	wait_ms(WAIT_TIME);
    	turn_off_led();
    	wait_ms(WAIT_TIME);
    }
    return 0 ;
}
