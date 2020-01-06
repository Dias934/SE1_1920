/**
* @file		menu_maintenance.h
* @brief	Contains the Menu Maintenance functions.
* @version	1.1
* @date		4 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/
#ifndef MENU_MAINTENANCE_H_
#define MENU_MAINTENANCE_H_

#include "menu.h"
#include "menu_normal.h"

/** @defgroup MENU_MAINTENANCE Menu Maintenance
 * This package provides the core capability of Menu Maintenance mode.
 * @{
 */
/** @defgroup MENU_MAINTENANCE_Public_Constants Menu Maintenance Public Constants
 * @{
*/
/**
 * @brief 10s=10000 milisec
 */
#define TEN_SECONDS 10000
/**
 * @}
 */
/** @defgroup MENU_MAINTENANCE_Public_Function Menu Maintenance Public Function
 * @{
*/
/**
 * @return returns a pointer to a maintenance function
 */
void * maintenance_execution();
/**
 * @}
 * @}
 */
#endif /* MENU_MAINTENANCE_H_ */
