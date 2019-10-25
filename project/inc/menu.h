/*
 * Menu.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef MENU_H_
#define MENU_H_

#include "peripherals.h"

extern uint32_t count;
extern uint32_t count_10;
extern int button_map;
extern char str[16];

#define TWO_SECONDS 2000
#define TEN_SECONDS 10000

#define PRESSING_TIME 250
#define RELEASE_TIME 100

uint32_t * init_menu();

uint32_t * up_and_down_pressed(uint32_t* origen(), uint32_t *destiny(), uint32_t *led_state());

#endif /* MENU_H_ */
