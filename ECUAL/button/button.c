/*
 * button.c
 *
 * Created: 4/5/2023 11:11:38 PM
 *  Author: Omar Taha
 */ 
#include "button.h"

/************************************************************************/
/*Description: Initialize a button as an Input                          */
/*@param u8_a_pinNumber  pin number                                     */
/*@param u8_a_portNumber port number                                    */
/************************************************************************/
err_state BUTTON_init(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber)
{
    DIO_init(u8_a_pinNumber,u8_a_portNumber,INPUT);
    return SUCCESS;
}

/************************************************************************/
/*Description: Read a button current state                              */
/*@param u8_a_pinNumber     pin number                                  */
/*@param u8_a_portNumber    port number                                 */
/*@param *en_a_value             refrence to store the read value in    */
/************************************************************************/
err_state BUTTON_read(uint8_t u8_a_pinNumber, uint8_t u8_a_portNumber, pin_state *en_a_value)
{
    DIO_read(u8_a_pinNumber,u8_a_portNumber,en_a_value);
    return SUCCESS;
}