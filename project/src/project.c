/*
===============================================================================
 Name        : project.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "menu.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	void *(*menu_execute)()=init_menu();
    while(1) {
    	menu_execute=menu_execute();
    }
    return 0 ;
}
