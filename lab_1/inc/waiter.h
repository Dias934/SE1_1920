#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

extern uint32_t __ms;
extern uint32_t start_wait_time;

extern void wait(int millis);

extern void wait_hz(int frequency);

extern void wait_init();

extern void wait_ms(int time);

extern uint32_t wait_elapsed();
