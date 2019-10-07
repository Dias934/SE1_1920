#include <led.h>

void init_led(){
	LPC_GPIO0->FIODIR|=(1<<22);
}

void turn_on_led(){
	LPC_GPIO0->FIOSET=(1<<22);
}

void turn_off_led(){
	LPC_GPIO0->FIOCLR=(1<<22);
}
