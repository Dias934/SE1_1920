/*
 * led.h
 *
 *  Created on: 01/10/2019
 *      Author: A38866
 */

#ifndef LED_H_
#define LED_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

void init_led();

void turn_on_led();

void turn_off_led();

int led_get_state();

#endif /* LED_H_ */
