/*
 * wait.h
 *
 *  Created on: 01/10/2019
 *      Author: A38866
 */

#ifndef WAIT_H_
#define WAIT_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

extern uint32_t __ms;

/**
 *
 */
void wait_init();

void wait_hz(int frequency);

void wait_ms(int millis);

uint32_t wait_elapsed(uint32_t time);

#endif /* WAIT_H_ */
