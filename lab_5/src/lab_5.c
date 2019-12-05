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
#include "peripherals.h"
#include "BMP280.h"
#include "stdlib.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	init_peripherals();
	init_bmp280();
	while (1) {
		LCDText_Locate(0,0);
		measure();
		LCDText_Printf("Temp:%.2f",current_temp);
		LCDText_Locate(1,0);
		LCDText_Printf("Pres:%.2f",current_press);
		wait_ms(500);
	}
	return 0;
}

