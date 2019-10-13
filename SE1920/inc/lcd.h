/**
* @file		button.h
* @brief	Contains the buttons interaction.
* @version	1.1
* @date		4 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/

#ifndef LCD_H_
#define LCD_H_


#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include "wait.h"
#include "HD44780.h"

#define LCD_DB4 23
#define LCD_DB5 24
#define LCD_DB6 25
#define LCD_DB7 26
#define LCD_ENABLE 30
#define LCD_RS 31

#define PINCFG_DB4 14
#define PINCFG_DB5 16
#define PINCFG_DB6 18
#define PINCFG_DB7 20
#define PINCFG_ENABLE 28
#define PINCFG_RS 30

void LCDText_Init(void);
/* Faz a iniciação do sistema para permitir o acesso ao periférico LCD,
utilizando 2 linhas com 16 colunas e comunicação a 4 bits. */

void LCDText_WriteChar(char ch);
/* Escreve um carácter na posição corrente do cursor. */

void LCDText_WriteString(char *str);
/* Escreve uma string na posição corrente do cursor. */

void LCDText_Locate(int row, int column);
/* Posiciona o cursor na linha row e coluna column do mostrador. */

void LCDText_Clear(void);
/* Limpa o visor, usando o comando disponível na API do periférico. */

void LCDText_Printf(char *fmt, ...); /* DESAFIO */
/* Escreve na posição corrente do cursor a string fmt. O formato da string fmt é
idêntico à função printf da biblioteca standard da linguagem C. */


#endif /* LCD_H_ */
