/*
 * led.h
 *
 * Created: 4/5/2023 6:23:05 PM
 *  Author: Omar Taha
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/dio/dio.h"
#include "../../MCAL/timers/timers.h"

/************************************************************************/
/*Description: Initialize a led as an output                            */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_init(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort);

/************************************************************************/
/*Description: Sets a led state as HIGH                                 */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_on(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort);

/************************************************************************/
/*Description: Sets a led state as LOW                                  */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_off(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort);

/************************************************************************/
/*Description: Toggles a led state                                      */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_toggle(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort);

/************************************************************************/
/*Description: Blink a led depending on the on and off times            */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/*@param f_a_onTime led on time                                         */
/*@param f_a_offTime led off time                                       */
/************************************************************************/
err_state LED_blink(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort,float f_a_onTime, float f_a_offTime);



/******************************************************************************/
/*Description: Blink an array of leds depending on the on and off times       */
/*@param u8_a_mask mask for the array of leds                                 */
/*@param u8_a_ledPort port number                                             */
/*@param f_a_onTime led on time                                               */
/*@param f_a_offTime led off time                                             */
/******************************************************************************/
err_state LED_array_blink(uint8_t u8_a_mask, uint8_t u8_a_ledPort,float f_a_onTime, float f_a_offTime);

/************************************************************************/
/*Description: Sets the state of an array of leds to HIGH               */
/*@param u8_a_mask mask for the array of leds                           */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_array_on(uint8_t u8_a_mask, uint8_t u8_a_ledPort);

/************************************************************************/
/*Description: Sets the state of an array of leds to LOW                */
/*@param u8_a_mask mask for the array of leds                           */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_array_off(uint8_t u8_a_mask, uint8_t u8_a_ledPort);




#endif /* LED_H_ */