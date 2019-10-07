/**
* @file		wait.h
* @brief	Contains the delay API.
* @version	1.1
* @date		4 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/

#ifndef WAIT_H_
#define WAIT_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

/** @defgroup WAIT Wait
 * This package provides the core capabilities for wait functions.
 * @{
 */

/** @defgroup WAIT_Public_Variables Wait Public Variables
 * @{
*/

/**
 * @brief	counts time
 * @note lowest resolution is 1ms
*/
extern uint32_t __ms;
/**
 * @}
 */

/** @defgroup WAIT_Public_Functions Wait Public Functions
 * @{
 */
/**
 * @brief	Initialises the wait API for 1 ms resolution.
 * @note	This function must be called prior to any other WAIT functions.
 */
void wait_init();

/**
 * @brief	waits the corresponding time from hz to ms.
 * @param	frequency: the whole number of hertz to wait.
 * @note created for applications that needs a certain frequency. Blocking function
 */

void wait_hz(int frequency);

/**
 * @brief	Waits a number of milliseconds.
 * @param	millis: the whole number of milliseconds to wait.
 * @note blocking function
 */
void wait_ms(int millis);

/**
 * @brief	Counts the time that has passed since the time received.
 * @param	time: start time.
 * @return	millis: the time that has passed or the current time if input parameter = 0.
 * @note not blocking function
 */
uint32_t wait_elapsed(uint32_t time);

/**
 * @}
 */


/**
 * @}
 */

#endif /* WAIT_H_ */
