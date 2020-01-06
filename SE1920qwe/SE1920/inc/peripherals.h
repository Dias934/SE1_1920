/**
* @file		Peripherals.h
* @brief	Contains the Peripherals interaction.
* @version	1.1
* @date		4 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/

#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

#include "ui.h"
#include "wait.h"
#include "rtc.h"
#include "spi.h"

/** @defgroup PERIPHERALS Peripherals
 * This package provides the connection function of Peripherals.
 * @{
 */
/** @defgroup Peripherals_Public_Functions Peripherals Public Functions
 * @{
*/
/**
 * @brief initialize the peripherals
 * @note must be called first
 */
void init_peripherals();
/**
 * @}
 * @}
 */

#endif /* PERIPHERALS_H_ */
