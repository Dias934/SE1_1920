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
#include "iap.h"
#include "stdlib.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define DST_LOCATION 0x00078023

static unsigned int* dstAddr=(unsigned int*)DST_LOCATION;

int main(void) {
	int sector=29;
	int value=0xA55A;
	init_peripherals();
	if(FLASH_BlankSectors(sector,sector)==SECTOR_NOT_BLANK)
		value=*dstAddr;
	//FLASH_EraseSectors(sector,sector);
	while (1) {
		LCDText_Locate(0,0);
		LCDText_Printf("value:%d",value);
		LCDText_Locate(1,0);
		FLASH_WriteData(dstAddr, &value, 4);
		LCDText_Printf("flash:%d",*dstAddr);
		wait_ms(2000);
		LCDText_Clear();
		wait_ms(100);
		value++;
	}
	return 0;
}

