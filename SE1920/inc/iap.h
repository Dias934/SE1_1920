/*
 * iap.h
 *
 *  Created on: 21/11/2019
 *      Author: A38866
 */

#ifndef IAP_H_
#define IAP_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#define IAP_LOCATION 0x1FFF1FF1

#define SRAM_LOCATION 0x2007C000

#define ONE_K 1024
#define FOUR_K 4*ONE_K
#define THIRTY_TWO_K 32*ONE_K

enum IAP_STATUS{
	CMD_SUCCESS,
	INVALID_COMMAND,
	SRC_ADDR_ERROR,
	DST_ADDR_ERROR,
	SRC_ADDR_NOT_MAPPED,
	DST_ADDR_NOT_MAPPED,
	COUNT_ERROR,
	INVALID_SECTOR,
	SECTOR_NOT_BLANK,
	SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION,
	COMPARE_ERROR,
	BUSY
};

enum IAP_COMMAND_CODES{
	PREPARE_FOR_WRITE =50,
	COPY_RAM_FLASH,
	ERASE,
	BLANK_CHECK,
	READ_PART_ID,
	READ_BOOT_VERSION,
	COMPARE,
	REINVOKE_ISP,
	READ_SERIAL_NUMBER
};

typedef void (*IAP)(unsigned int [],unsigned int[]);

unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector);

unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size);

unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size);

unsigned int FLASH_BlankSectors(unsigned int startSector, unsigned int endSector);

#endif /* IAP_H_ */
