/*
 * menu_maintenance.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef MENU_MAINTENANCE_H_
#define MENU_MAINTENANCE_H_

#include "menu.h"
#include "menu_change_field.h"

typedef struct{
	uint32_t *(*change_time)();
	uint32_t *(*change_date)();
	uint32_t *(*change_temp_unit)();
}Views;

void view_maintenance();

uint32_t * maintenance_execution();

#endif /* MENU_MAINTENANCE_H_ */
