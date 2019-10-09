/*
===============================================================================
 Name        : project.c
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

#include "ui.h"
#include "menu.h"
#include "data_storage.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

	init_ui();
	init_data_st(0);
	set_Date(9,10,2019);
	uint32_t *(*menu_execute)()=init_menu();
    while(1) {
    	menu_execute=menu_execute();
    }
    return 0 ;
}
