#include "lcd.h"

short row;
short col;

void LCDText_Write_4bits(int rs, int data);

void LCDText_Send_4bits(int  rs, int data);

void LCDText_Init(void){
	LPC_PINCON->PINSEL1 &=~((3<<PINCFG_DB4) | (3<<PINCFG_DB5) | (3<<PINCFG_DB6) | (3<<PINCFG_DB7));
	LPC_PINCON->PINSEL3 &=~((3<<PINCFG_ENABLE) | (3<<PINCFG_RS));
	LPC_GPIO0->FIODIR|=(1<<LCD_DB4)|(1<<LCD_DB5)|(1<<LCD_DB6)|(1<<LCD_DB7);
	LPC_GPIO1->FIODIR|=(1<<LCD_ENABLE)|(1<<LCD_RS);
	wait_ms(40);
	LCDText_Send_4bits(COMMAND,INIT_VAL);
	wait_ms(5);
	LCDText_Send_4bits(COMMAND,INIT_VAL);
	wait_ChronoUs(100);
	LCDText_Send_4bits(COMMAND,INIT_VAL);
	LCDText_Send_4bits(COMMAND,(FUNCTION_SET_CMD | FOUR_BIT<<DL_POSITION)>>4); //set datalength to 4bits write mode
	wait_ChronoUs(100);
	LCDText_Write_4bits(COMMAND, FUNCTION_SET_CMD | FOUR_BIT<<DL_POSITION | TWO_LINES<<N_POSITION | TEN_DOT_FONT<<F_POSITION);
	LCDText_Write_4bits(COMMAND, DISPLAY_CONTROL_CMD | DISPLAY_OFF<<D_POSITION | CURSOR_OFF<<C_POSITION | BLINK_CURSOR_OFF<<B_POSITION);
	LCDText_Write_4bits(COMMAND, CLEAR_DISPLAY_CMD);
	LCDText_Write_4bits(COMMAND, ENTRY_MODE_SET_CMD | INCREMENT<<I_D_POSITION | SHIFT_ENABLE<<S_POSITION);
	LCDText_Write_4bits(COMMAND, RETURN_HOME_CMD);
	wait_ms(2); //home command requires at least 1.52ms of execution time
	LCDText_Write_4bits(COMMAND, DISPLAY_CONTROL_CMD | DISPLAY_ON<<D_POSITION | CURSOR_OFF<<C_POSITION | BLINK_CURSOR_OFF<<B_POSITION);
	row=0;
	col=0;
}

void LCDText_Write_4bits(int rs, int data){
	LCDText_Send_4bits(rs,data>>4);
	LCDText_Send_4bits(rs,data);
	wait_ChronoUs(37);
}

void write_pin(int val, int pin){
	if(val>0)LPC_GPIO0->FIOSET|=(1<<pin);
	else LPC_GPIO0->FIOCLR|=(1<<pin);
}

void LCDText_Send_4bits(int  rs, int data){
	if(rs==DATA)LPC_GPIO1->FIOSET|=(1<<LCD_RS);
	else LPC_GPIO1->FIOCLR|=(1<<LCD_RS);
	write_pin(data&1,LCD_DB4);
	write_pin((data>>1)&1,LCD_DB5);
	write_pin((data>>2)&1,LCD_DB6);
	write_pin((data>>3)&1,LCD_DB7);
	LPC_GPIO1->FIOSET|=(1<<LCD_ENABLE);
	wait_ChronoUs(1);
	LPC_GPIO1->FIOCLR|=(1<<LCD_ENABLE);
	wait_ChronoUs(1);
}

void LCDText_WriteChar(char ch){
	LCDText_Write_4bits(DATA,ch);
}
void LCDText_WriteString(char *str){
	for (short i= 0; str[i]!= '\0'; ++i) {
		if(i+col==16){
			if(row==1)LCDText_Locate(0,0);
			else LCDText_Locate(1,0);
		}
		LCDText_WriteChar(str[i]);
	}
}

void LCDText_Locate(int row, int column){
	LCDText_Write_4bits(COMMAND, SET_DDRAM_ADDR_CMD | (row<<ROW_POSITION) | (column&MAX_COL_VALUE));
	this->row=row;
	col=column;
}

void LCDText_Clear(void){
	LCDText_Write_4bits(COMMAND, CLEAR_DISPLAY_CMD);
	wait_ms(2);// The clear display command send the cursor home too
}

void LCDText_Printf(char *fmt, ...){

}/* DESAFIO */




