/*
 ===============================================================================
 Name        : lab_3.c
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
#include <peripherals.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	init_peripherals();
	int a;
	while (1) {
		a=BUTTON_Read();
		LCDText_Clear();
		LCDText_PrintBinary(a);
		wait_ms(200);
	}
	return 0;
}

