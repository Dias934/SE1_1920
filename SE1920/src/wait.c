/*
 * wait.c
 *
 *  Created on: 01/10/2019
 *      Author: A38866
 */
#include <wait.h>

uint32_t __ms=0;

void wait_init(void){
	SysTick_Config(SystemCoreClock/1000);
}

void wait_hz(int frequency){
	uint32_t conv_ms=((double)1/frequency)*1000;
	wait_ms(conv_ms);
}

void wait_ms(int millis){
	uint32_t start=__ms;
	while((__ms-start)<millis);
}

uint32_t wait_elapsed(uint32_t time){
	if(time==0) return __ms;
	return __ms-time;
}

void SysTick_Handler(void){
	++__ms;
}
