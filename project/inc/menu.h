/*
 * Menu.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef MENU_H_
#define MENU_H_

#include "menu_normal.h"
#include "menu_maintenance.h"

extern uint32_t count;
extern int button_map;

#define TWO_SECONDS 2000
#define TEN_SECONDS 10000

uint32_t * init_menu();
uint32_t * up_and_down_pressed(uint32_t* origen(), uint32_t *destiny(), uint32_t *led_state());

#endif /* MENU_H_ */
