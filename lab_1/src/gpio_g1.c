#include <gpio_g1.h>


void init_led2(){
	LPC_GPIO0->FIODIR|=(1<<22);
}

void turn_on_led2(){
	LPC_GPIO0->FIOSET=(1<<22);
}

void turn_off_led2(){
	LPC_GPIO0->FIOCLR=(1<<22);
}
