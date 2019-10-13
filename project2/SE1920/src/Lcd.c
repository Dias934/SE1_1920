#include "Lcd.h"

void LCDText_Init(void){
	LPC_PINCON->PINSEL1 &=~((3<<14) | (3<<16) | (3<<18) | (3<<20));
	LPC_PINCON->PINSEL3 &=~((3<<28) | (3<<30));


	LPC_GPIO0->FIODIR|=(1<<LCD_PIN1);
	LPC_GPIO0->FIODIR|=(1<<LCD_PIN2);
	LPC_GPIO0->FIODIR|=(1<<LCD_PIN3);
	LPC_GPIO2->FIODIR|=(1<<LCD_PIN4);
	LPC_GPIO2->FIODIR|=(1<<LCD_PIN_ENABLE);
	LPC_GPIO2->FIODIR|=(1<<LCD_PIN_RS);


	wait_ms(15);
	LCDText_Write5bits(0,3);
	wait_ms(5);
	wait_ChronoUs(1);
	wait_ChronoUs(100);

	LCDText_Write5bits(0,2);
	LCDText_Write5bits(0,4);

	LCDText_Write5bits(0,0);
	LCDText_Write5bits(0,8);

	LCDText_Write5bits(0,0);
	LCDText_Write5bits(0,1);

	LCDText_Write5bits(0,0);
	LCDText_Write5bits(0,2);

}

void LCDText_Write5bits(int rs, int data){

	LPC_GPIO1->FIOSET=(rs<<LCD_PIN_RS) | (1<<LCD_PIN_ENABLE);
	LPC_GPIO0->FIOSET=((data&1)<<LCD_PIN1) | (((data>>1)&1)<<LCD_PIN2) | (((data>>2)&1)<<LCD_PIN3);
	LPC_GPIO0->FIOSET=(((data>>3)&1)<<LCD_PIN4);

	LPC_GPIO1->FIOCLR=(rs<<LCD_PIN_RS) | (1<<LCD_PIN_ENABLE);
	LPC_GPIO0->FIOCLR=((data&1)<<LCD_PIN1) | (((data>>1)&1)<<LCD_PIN2) | (((data>>2)&1)<<LCD_PIN3);
	LPC_GPIO0->FIOCLR=(((data>>3)&1)<<LCD_PIN4);

}

void LCDText_WriteChar(char ch){

	LCDText_Write5bits(0,0);
	LCDText_Write5bits(0,14);
	LCDText_Write5bits(0,0);
	LCDText_Write5bits(0,6);
	LCDText_Write5bits(1,ch<<4);
	LCDText_Write5bits(1,ch);

}
void LCDText_WriteString(char *str){

}
void LCDText_Locate(int row, int column){

}
void LCDText_Clear(void){

}
void LCDText_Printf(char *fmt, ...){

}/* DESAFIO */




