/**
* @file		wait.h
* @brief	Contains the delay API.
* @version	1.1
* @date		10 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/

#ifndef LED_H_
#define LED_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif




/** @defgroup LED LED
 * This package provides the core capabilities such as on / off the LED in
 * the LPC1769 from NXP.
 * @{
 */

/** @defgroup LED_Public_Functions LED Public Functions
 * @{
 */

/**
 * @brief	Initializes the LED API
 * @param	state	: State of the LED. The 0 indicate led off and 1 LED on.
 * @return	Nothing
 * @note	This function must be called prior to any other LED functions. The
 * LED will started in the value passed in the parameter.
 */
void init_led();
/**
 * @brief	Turn LED on
 * @return	Nothing
 */
void turn_on_led();
/**
 * @brief	Turn LED off
 * @return	Nothing
 */
void turn_off_led();
/**
 * @brief	Get LED state.
 * @return	status of LED. The 0 indicate led is off and 1 LED is on.
 */
int led_GetState();
/**
 * @}
 */

/**
 * @}
 */

#endif /* LED_H_ */
