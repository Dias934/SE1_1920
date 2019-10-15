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
#include <ui.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	init_ui();
	LCDText_Printf("oiqerhoewrowergoqeboqerbogbweroboerboq: %d",15);
	while (1) {
		wait_ms(200);
	}
	return 0;
}

