/**
* @file		led.h
* @brief	Contains the LED API.
* @version	1.0
* @date		7 Out 2018
* @author	PSampaio
*
* Copyright(C) 2015-2018, PSampaio
* All rights reserved.
*
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
**********************************************************************/

#ifndef _LED_H_
#define _LED_H_

/** @defgroup LED LED
 * This package provides the core capabilities such as on / off the LED in
 * port P0.22 of the LPC1769 from NXP.
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
void LED_Init(int state);


/**
 * @brief	Get LED state. 
 * @return	status of LED. The 0 indicate led is off and 1 LED is on.
 */
int LED_GetState(void);

/**
 * @brief	Turn LED on
 * @return	Nothing
 */
void LED_On(void);

/**
 * @brief	Turn LED off
 * @return	Nothing
 */
void LED_Off(void);

/**
 * @}
 */


/**
 * @}
 */

#endif /* _LED_H_ */

