/*
 * view.c
 *
 *  Created on: 28/10/2019
 *      Author: A38866
 */

#include "view.h"

char str[32];

const char * MAINTENANCE_CHANGE_TITLE[]={"Change Time","Change Date","Change Temp. Un"};

void view_normal(){
	LCDText_Locate(0,0);
	dateTimeToString(str);
	LCDText_WriteString(str);
	LCDText_Locate(1,0);
	//TemperatureAndPressureToString(str);
	//LCDText_WriteString(str);
}

void view_maintenance(short idx){
	LCDText_Locate(0,0);
	LCDText_WriteString(MAINTENANCE_CHANGE_TITLE[idx]);
	LCDText_Locate(1,0);
	LCDText_WriteString(str);
}

void view_change_time(){
	get_Time(str);
	view_maintenance(0);
}

void view_change_date(){
	get_Date(str);
	view_maintenance(1);
}

void view_change_temperature_units(){
	view_maintenance(2);
}
