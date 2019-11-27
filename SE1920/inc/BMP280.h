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



#define WR 0x7F
#define RD 0xFF

#define ID_ADDR 0xD0
#define ID_VALUE 0x58


#define RESET_ADDR 0xE0
#define RESET_VAL 0xB6


#define CTRL_MEAS_ADDR 0xF4

#define PWR_MODE_BIT 0
enum PWR_MODE{
	SLEEP_MODE=0,
	FORCED_MODE,
	NORMAL_MODE=3
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
enum FILTER_COEF_VAL{
	FILTER_OFF=0,
	FILTER_2,
	FILTER_4=4,
	FILTER_8,
	FILTER_16
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

#define CALIB_DATA_ADDR_INIT 0X88
#define CALIB_TEMP_ADDR_INIT 0x88
#define CALIB_TEMP_ADDR_END 0x8D
#define CALIB_PRESS_ADDR_INIT 0x8E
#define CALIB_PRESS_ADDR_END 0x9F
#define CALIB_DATA_ADDR_END 0X9F

typedef struct{
	unsigned short dig_T1;
	short dig_T2;
	short dig_T3;
	unsigned short dig_P1;
	short dig_P2;
	short dig_P3;
	short dig_P4;
	short dig_P5;
	short dig_P6;
	short dig_P7;
	short dig_P8;
	short dig_P9;
}bmp280_calib_data_Typedef;

extern bmp280_calib_data_Typedef calib_data;
extern double current_temp;
extern double current_press;

void init_bmp280();

int get_chip_ID();

int measure();

#endif /* BMP280_H_ */
