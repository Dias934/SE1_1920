#include <waiter.h>

uint32_t __ms=0;
uint32_t start_wait_time=0;

void wait_init(){
	SysTick_Config(SystemCoreClock/1000);
}

void wait(int millis){
	uint32_t start=__ms;
	while((__ms-start)<millis);
}

void wait_hz(int frequency){
	uint32_t conv_ms=((double)1/frequency)*1000;
	wait(conv_ms);
}

void wait_ms(int time){

}

uint32_t wait_elapsed(){
	return __ms;
}

void SysTick_Handler(void){
	++__ms;
}
