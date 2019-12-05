/*
 * Menu.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef MENU_H_
#define MENU_H_

#include "peripherals.h"
#include "view.h"

extern uint32_t count;
extern int button_map;

#define ONE_SECOND 1000

#define TWO_SECONDS 2000

#define PRESSING_TIME 250
#define RELEASE_TIME 100

void *init_menu();

void *up_and_down_pressed(void *origen(), void *destiny(), void (*led_state)());

#endif /* MENU_H_ */
