/*
 * BMP280.h
 *
 *  Created on: 13/11/2019
 *      Author: A38866
 */

#ifndef BMP280_H_
#define BMP280_H_

#ifdef __USE_CMSIS
#include "spi.h"
#include "LPC17xx.h"
#endif

#define CS_PIN 9 //CS pin is Pin 9 of Port0 (default pin)
#define PORT_NUMBER 0

#define INIT_SUCC 0
#define DEFAULT_INIT_MODE 1

enum RET_STATUS{
	SUCCESSFUL,
	ERROR
};



#define SPI_FREQUENCY 10000000


#define ID_ADDR 0xD0
#define ID_VALUE 0x58


#define RESET_ADDR 0xE0
#define RESET_VAL 0xB6


#define CTRL_MEAS_ADDR 0xF4

#define PWR_MODE_BIT 0
enum PWR_MODE{
	SLEEP_MODE=0,
	FORCED_MODE,
	NORMAL_MODE
};

#define OSR_P_BIT 2
#define OSR_T_BIT 5
enum OSR_VAL{
	SKIPPED =0,
	OVERSAMPLE_ONE,
	OVERSAMPLE_TWO,
	OVERSAMPLE_FOUR,
	OVERSAMPLE_EIGHT,
	OVERSAMPLE_SIXTEEN
};


#define CONFIG_ADDR 0xF5

#define SPI3W_EN_BIT 0
enum SPI3W_EN_VAL{
	I2C=0,
	SPI
};

#define FILTER_BIT 2
enum FILTER_VAL{
	DEFAULT_FILTER=4
};
#define T_SB_BIT 5
enum T_SB_VAL{
	TIME_HALF_MS=0,
	TIME_62_HALF_MS,
	TIME_125_MS,
	TIME_250_MS,
	TIME_500_MS,
	TIME_1_SEC,
	TIME_2_SEC,
	TIME_4_SEC
};

#define PRESSURE_DATA_ADDR 0xF7
#define TEMPERATURE_DATA_ADDR 0xFA

#define CALIB_DATA_ADDR_INIT 0X89
#define CALIB_DATA_ADDR_END 0XA0

typedef struct{
	uint16_t dig_T1;
	int16_t dig_T2;
	int16_t dig_T3;
	uint16_t dig_P1;
	int16_t dig_P2;
	int16_t dig_P3;
	int16_t dig_P4;
	int16_t dig_P5;
	int16_t dig_P6;
	int16_t dig_P7;
	int16_t dig_P8;
	int16_t dig_P9;
}bmp280_calib_data_Typedef;

extern bmp280_calib_data_Typedef calib_data;
extern uint32_t current_temp;
extern uint32_t current_press;

void init_bmp280();

int write_spi(unsigned short *tx, unsigned short *rx, int length);

int get_status();

int set_default_use();


#endif /* BMP280_H_ */
