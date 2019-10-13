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
	while (1) {
		LCDText_WriteString("SE1");
		wait_ms(200);
		/*int idx=0;
		for (short c=0; c<16; ++c) {
			LCDText_Locate(0,c);
			LCDText_WriteChar('A'+idx++);
			wait_ms(500);
			LCDText_Locate(1,c);
			LCDText_WriteChar('A'+idx++);
			wait_ms(500);
		}*/
		LCDText_Clear();
		wait_ms(200);
	}
	return 0;
}

