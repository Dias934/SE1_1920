#include "Wait.h"
uint32_t __MS=0;
void wait_init(){

	SysTick_Config(SystemCoreClock/1000);
}
void wait_ms(int milis){

	uint32_t start=__MS;
	while((__MS-start)<milis);
}
void SysTick_Handler(void){
	++__MS;
}

uint32_t wait_elapsed(uint32_t time){
	if(time==0) return  __MS;
	return __MS-time;
}

void wait_hz(int frequency){
	uint32_t conv_ms=((double)1/frequency)*1000;
	wait_ms(conv_ms);
}
