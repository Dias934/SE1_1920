/*
 * menu_maintenance.h
 *
 *  Created on: 08/10/2019
 *      Author: A38866
 */

#ifndef MENU_MAINTENANCE_H_
#define MENU_MAINTENANCE_H_

#include "menu.h"
#include "menu_normal.h"

extern uint32_t count_10;

#define TEN_SECONDS 10000



typedef struct{
	void (*up_down_function)(short value);
	void (*enter_function)();
}Field_TYPEDEF;

typedef struct{
	void (*up_function)(short value);
	void (*enter_function)();
	void (*down_function)(short value);
}Select_field_TYPEDEF;

typedef struct{
	Select_field_TYPEDEF *select;
	Field_TYPEDEF *time;
	Field_TYPEDEF *date;
	Field_TYPEDEF *temp_units;
}Maintenance_F_PTRS_TYPEDEF;


void print_maintenance(char *str);

void maintenance_buttons_interaction();

void select_up_pressed(short value);

void select_down_pressed(short value);

void select_enter_pressed();

void time_up_down_pressed(short value);

void time_enter_pressed();

void select_field();

void maintenance_change_time();

void maintenance_change_date();

void maintenance_change_temperature_units();


void * maintenance_execution();

#endif /* MENU_MAINTENANCE_H_ */
