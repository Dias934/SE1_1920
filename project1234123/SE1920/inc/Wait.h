/**
* @file		wait.h
* @brief	Contains the delay API.
* @version	1.1
* @date		10 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/


#ifndef _WAIT_H_
#define _WAIT_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

//#include <cr_section_macros.h>
extern uint32_t __MS;

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
void wait_init();

/**
 * @brief	Counts the time that has passed since the time received.
 * @param	time: initial time.
 * @return	millis: the time that has passed.
 */
uint32_t wait_elapsed(uint32_t time);

/**
 * @brief	Waits a number of milliseconds.
 * @param	millis: the whole number of milliseconds to wait.
 */
void wait_ms(int milis);
/**
 * @brief	__MS increment.
 */
void SysTick_Handler(void);

/**
 * @brief	Waints a number of hertz.
 * @param	hertz: the whole number of hertz to wait.
 */
void wait_hz(int frequency);


/**
 * @}
 */


/**
 * @}
 */

#endif
