/**
* @file		wait.h
* @brief	Contains the delay API.
* @version	1.1
* @date		10 Out 2017
* @author	PSampaio
*
* Copyright(C) 2015-2017, PSampaio
* All rights reserved.
*
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
**********************************************************************/

#ifndef _WAIT_H_
#define _WAIT_H_

/** @defgroup WAIT Wait
 * This package provides the core capabilities for wait functions.
 * @{
 */

/** @defgroup WAIT_Public_Functions Wait Public Functions
 * @{
 */

/**
 * @brief	Initialises the wait API for 1 ms resolution.
 * @return	0 if initialisation successed; -1 if fails.
 * @note	This function must be called prior to any other WAIT functions.
 */
int WAIT_Init(void);


/**
 * @brief	Waits a number of milliseconds.
 * @param	millis: the whole number of milliseconds to wait.
 */
void WAIT_Ms(uint32_t millis);

/**
 * @}
 */


/**
 * @}
 */

#endif /* _LED_H_ */

