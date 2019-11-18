/*
 * BMP280.c
 *
 *  Created on: 13/11/2019
 *      Author: A38866
 */

#include "BMP280.h"

bmp280_calib_data_Typedef calib_data;
short* calib_ptr[]={&(calib_data.dig_T1),&(calib_data.dig_T2),&(calib_data.dig_T3),&(calib_data.dig_P1),&(calib_data.dig_P2),&(calib_data.dig_P3),
					   &(calib_data.dig_P4),&(calib_data.dig_P5),&(calib_data.dig_P6),&(calib_data.dig_P7),&(calib_data.dig_P8),&(calib_data.dig_P9)};
uint32_t current_temp;
uint32_t current_press;

static void get_calib_data(){
	unsigned short tx[2]={0,0};
	unsigned short rx[2]={0,0};
	SPI_ConfigTransfer(SPI_FREQUENCY,SIXTEEN_BITS,CPHA_CPOL_LL);
	int ret=SPIF;
	for(int i=CALIB_DATA_ADDR_INIT; i<CALIB_DATA_ADDR_INIT && ret==SPIF; i+=2){
		write_spi(tx, rx, 2);
		if(ret==SPIF){
			calib_ptr[(i-CALIB_DATA_ADDR_INIT)/2]=rx[1];
		}
	}
}

void init_bmp280(){
	LPC_PINCON->PINSEL0&=~(3<<18);
	LPC_GPIO0->FIODIR|=(1<<CS_PIN);
	LPC_GPIO0->FIOSET|=(1<<CS_PIN);
	get_calib_data();
}

int get_status(){
	unsigned short tx[2]={ID_ADDR,0};
	unsigned short rx[2]={0,0};
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	int ret=write_spi(tx,rx,2);
	if(ret==SPIF)
		ret=rx[1];
	return ret;
}

int write_spi(unsigned short *tx, unsigned short *rx, int length){
	LPC_GPIO0->FIOCLR|=(1<<CS_PIN);
	int ret=SPI_Transfer(tx, rx, length);
	LPC_GPIO0->FIOSET|=(1<<CS_PIN);
	return ret;
}

int set_default_use(){
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	unsigned short tx[4]={CTRL_MEAS_ADDR, NORMAL_MODE | OVERSAMPLE_FOUR<<OSR_P_BIT | OVERSAMPLE_ONE<<OSR_T_BIT,
						  CONFIG_ADDR,DEFAULT_FILTER<<FILTER_BIT | TIME_125_MS<<T_SB_BIT};
	unsigned short rx[4]={0,0,0,0};
	return write_spi(tx, rx, 4);
}

int measure(){
	unsigned short tx[7]={PRESSURE_DATA_ADDR,0,0,0,0,0,0};
		unsigned short rx[7]={0,0,0,0,0,0,0};
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	int ret=write_spi(tx, rx, 7);
	if(ret==SPIF){

	}
	return ret;
}

uint32_t get_temperature(){
	return current_temp;
}

uint32_t get_pressure(){
	return current_press;
}
