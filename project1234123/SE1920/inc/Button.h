/**
* @file		wait.h
* @brief	Contains the delay API.
* @version	1.1
* @date		10 Out 2017
* @author	Ricardo Romano, André Dias, Manuel Dias
* @numbers  43924, 40619, 38866
*/

#ifndef _BUTTON_H_
#define _BUTTON_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
/** @defgroup BUTTON Button
 * This package provides the core capabilities for button functions.
 * @{
 */
/** @defgroup BUTTON_Public_Constants Button Public Constants
 * @{
*/

/** @defgroup BUTTON_Public_Buttons_Pins Button Public Buttons_Pins
 *  @brief	Buttons Pins
 *  @{
*/


#define UP_BUTTON_PIN 2
#define DOWN_BUTTON_PIN 3
#define ENTER_BUTTON_PIN 21

/**
 * @}
 */
/**
 * @brief	Buttons Pins at GPIO Register
*/
#define PINCFG_UP_BUTTON 2*UP_BUTTON_PIN
#define PINCFG_DOWN_BUTTON 2*DOWN_BUTTON_PIN
#define PINCFG_ENTER_BUTTON ENTER_BUTTON_PIN/2

/**
 * @brief	Buttons Function, using negative logic
 * @note 	Can be 3 (00), 2(01), 1(10), 0(11)
*/
#define PINCFG_PULLUP 3

/**
 * @brief	Buttons mask
*/
#define BUTTONS_MASK 0x0020000C
#define UP_BUTTON_MASK 0x00000004
#define DOWN_BUTTON_MASK 0x00000008
#define ENTER_BUTTON_MASK 0x00200000
/**
 * @brief	Buttons state
*/
#define NOT_PRESSED 0
#define PRESSED 1
#define PRESSING 2
#define RELEASED 3
/**
 * @brief	Buttons Struct to define state
*/
typedef struct{
	short up;
	short down;
	short enter;
}BUTTONS_STATE_TYPEDEF;

extern BUTTONS_STATE_TYPEDEF buttons_state;

/**
 * @}
 */

/** @defgroup BUTTON_Public_Functions Button Public Functions
 * @{
 */
/**
 * @brief	Initializes the Button API.
 * @note	This function must be called prior to any other BUTTON functions.
 */
void Button_init();

/**
 * @brief	Read the buttons values
 * @return	bitmap code 0 if there is no button pressed.
 */
int BUTTON_Hit(void);

/**
 * @brief	Call the Button_init function,  just one. Check if some button is pressed
 * @return	bitmap code.
 */
int BUTTON_Read(void);

/**
 * @brief	Check if there is any change at the buttons state
 * @return	Bitmap code.
 */
int BUTTON_GetButtonsEvents(void);

/**
 * @}
 */


/**
 * @}
 */

#endif

