/*
 * view.h
 *
 *  Created on: 28/10/2019
 *      Author: A38866
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "data_storage.h"
#include "lcd.h"

void view_normal();

void view_maintenance(short idx);

void view_change_time();

void view_change_date();

void view_change_temperature_units();

#endif /* VIEW_H_ */
