/*
 * led.c
 *
 * Created: 4/5/2023 6:22:55 PM
 *  Author: Omar Taha
 */ 

#include "led.h"


/************************************************************************/
/*Description: Initialize a led as an output                            */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_init(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort)
{
    DIO_init(u8_a_ledPin,u8_a_ledPort,OUTPUT);
    return SUCCESS;
}

/************************************************************************/
/*Description: Sets a led state as HIGH                                 */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_on(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort)
{
    DIO_write(u8_a_ledPin,u8_a_ledPort,HIGH);
    return SUCCESS;
}

/************************************************************************/
/*Description: Sets a led state as LOW                                  */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_off(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort)
{
    DIO_write(u8_a_ledPin,u8_a_ledPort,LOW);
    return SUCCESS;
}

/************************************************************************/
/*Description: Toggles a led state                                      */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_toggle(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort)
{
    DIO_toggle(u8_a_ledPin,u8_a_ledPort);
    return SUCCESS;
}

/************************************************************************/
/*Description: Blink a led depending on the on and off times            */
/*@param u8_a_ledPin pin number                                         */
/*@param u8_a_ledPort port number                                       */
/*@param f_a_onTime led on time                                         */
/*@param f_a_offTime led off time                                       */
/************************************************************************/
err_state LED_blink(uint8_t u8_a_ledPin, uint8_t u8_a_ledPort,float f_a_onTime, float f_a_offTime)
{
    LED_on(u8_a_ledPin,u8_a_ledPort);
    TIMER0_delay(f_a_onTime);
    LED_off(u8_a_ledPin,u8_a_ledPort);
    TIMER0_delay(f_a_offTime);
    return SUCCESS;
}


/************************************************************************/
/*Description: Sets the state of an array of leds to HIGH               */
/*@param u8_a_mask mask for the array of leds                           */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_array_on(uint8_t u8_a_mask, uint8_t u8_a_ledPort)
{
    DIO_array_write(u8_a_mask,u8_a_ledPort,HIGH);
    return SUCCESS;
}

/************************************************************************/
/*Description: Sets the state of an array of leds to LOW                */
/*@param u8_a_mask mask for the array of leds                           */
/*@param u8_a_ledPort port number                                       */
/************************************************************************/
err_state LED_array_off(uint8_t u8_a_mask, uint8_t u8_a_ledPort)
{
    DIO_array_write(u8_a_mask,u8_a_ledPort,LOW);
    return SUCCESS;
}

// err_state LED_array_toggle(uint8_t u8_a_mask, uint8_t u8_a_ledPort)
// {
// 	DIO_array_toggle(u8_a_mask,u8_a_ledPort);
// 	return SUCCESS;
// }


/******************************************************************************/
/*Description: Blink an array of leds depending on the on and off times       */
/*@param u8_a_mask mask for the array of leds                                 */
/*@param u8_a_ledPort port number                                             */
/*@param f_a_onTime led on time                                               */
/*@param f_a_offTime led off time                                             */
/******************************************************************************/
err_state LED_array_blink(uint8_t u8_a_mask, uint8_t u8_a_ledPort,float f_a_onTime, float f_a_offTime)
{
    LED_array_on(u8_a_mask,u8_a_ledPort);
    TIMER0_delay(f_a_onTime);
    LED_array_off(u8_a_mask,u8_a_ledPort);
    TIMER0_delay(f_a_offTime);
    return SUCCESS;
}