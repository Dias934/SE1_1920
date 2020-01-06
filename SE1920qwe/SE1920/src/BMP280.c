#include "BMP280.h"

bmp280_calib_data_Typedef calib_data;
signed short* calib_signed_ptr[]={&(calib_data.dig_T1),&(calib_data.dig_T2),&(calib_data.dig_T3),&(calib_data.dig_P1),&(calib_data.dig_P2),&(calib_data.dig_P3),&(calib_data.dig_P4),
		&(calib_data.dig_P5),&(calib_data.dig_P6),&(calib_data.dig_P7),&(calib_data.dig_P8),&(calib_data.dig_P9)};
double current_temp;
double current_press;


static int write_spi(unsigned short *tx, unsigned short *rx, int length){
	LPC_GPIO0->FIOCLR|=(1<<CS_PIN);
	int ret=SPI_Transfer(tx, rx, length);
	LPC_GPIO0->FIOSET|=(1<<CS_PIN);
	return ret;
}

static void get_calib_data(){
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	int ret=SPIF;
	unsigned short tx[25];
	unsigned short rx[25];
	tx[0]=CALIB_DATA_ADDR_INIT&RD;
	write_spi(tx, rx, 25);
	if(ret==SPIF)
		for (int i = 0; i<12; i++)
			(*calib_signed_ptr[i])=rx[i*2+1] | rx[i*2+2]<<8;
}

static void set_default_use(){
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	unsigned short tx[4]={CTRL_MEAS_ADDR&WR, NORMAL_MODE | OVERSAMPLE_FOUR<<OSR_P_BIT | OVERSAMPLE_ONE<<OSR_T_BIT,
						  CONFIG_ADDR&WR,FILTER_4<<FILTER_BIT | TIME_125_MS<<T_SB_BIT};
	unsigned short rx[4]={0,0,0,0};
	write_spi(tx, rx, 4);
}

void init_bmp280(){
	LPC_PINCON->PINSEL0&=~(3<<18);
	LPC_GPIO0->FIODIR|=(1<<CS_PIN);
	LPC_GPIO0->FIOSET|=(1<<CS_PIN);
	get_calib_data();
	set_default_use();
}

int get_chip_ID(){
	unsigned short tx[2]={ID_ADDR&RD,0};
	unsigned short rx[2]={0,0};
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	int ret=write_spi(tx,rx,2);
	if(ret==SPIF)
		ret=rx[1];
	return ret;
}

int measure(){
	unsigned short tx[7]={PRESSURE_DATA_ADDR&RD,0,0,0,0,0,0};
		unsigned short rx[7]={0,0,0,0,0,0,0};
	SPI_ConfigTransfer(SPI_FREQUENCY,EIGHT_BITS,CPHA_CPOL_LL);
	int ret=write_spi(tx, rx, 7);
	if(ret==SPIF){
		unsigned int adc_p=rx[1]<<12 | rx[2]<<4 | rx[3]>>4;
		unsigned int adc_t=rx[4]<<12 | rx[5]<<4 | rx[6]>>4;
		int var1, var2, t_fine;
		long var3, var4;
		var1=(((double)adc_t)/16384.0-((double)calib_data.dig_T1)/1024.0)*((double)calib_data.dig_T2);
		var2=((((double)adc_t)/131072.0-((double)calib_data.dig_T1)/8192.0)*(((double)adc_t)/131072.0-((double)calib_data.dig_T1)/8192.0))*((double)calib_data.dig_T3);
		t_fine=(int)(var1+var2);
		current_temp=(var1+var2)/5120.0;
		var3=((double)t_fine/2.0)-64000.0;
		var4=var3*var3*((double)calib_data.dig_P6)/32768.0;
		var4=var4+var3*((double)calib_data.dig_P5)*2.0;
		var4=(var4/4.0)+(((double)calib_data.dig_P4)*65536.0);
		var3=(((double)calib_data.dig_P3)*var3*var3/524288.0+((double)calib_data.dig_P2)*var3)/524288.0;
		var3=(1.0+var3/32768.0)*((double)calib_data.dig_P1);
		current_press=1048576.0-(double)adc_p;
		current_press=(current_press-(var4/4096.0))*6250.0/var3;
		var3=((double)calib_data.dig_P9)*current_press*current_press/2147483648.0;
		var4=current_press*((double)calib_data.dig_P8)/32768.0;
		current_press=current_press+(var3+var4+((double)calib_data.dig_P7))/16.0;
	}
	return ret;
}
