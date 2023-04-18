/*
 * File: lcd_interface.h
 * Created Date: Monday, April 17th 2023, 1:21:36 am
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "lcd_private.h"
#include "../../MCAL/timers/timers.h"
#include "../../Utilities/bit_manipulation.h"

/*                              8 bit mode                                 */

/***************************************************************************/
/** @brief  LCD 8 bit mode initialization function                         */
/** @param  void                                                           */
/** @return init_OK                                                        */
/***************************************************************************/
LCD_init_error LCD_8_bit_init(void);

/***************************************************************************/
/** @brief    Sends Commands to 8 bit mode LCD                             */
/** @param    u8_a_command   command to be sent to the LCD                 */
/** @return   cmnd_send_OK                                                 */
/***************************************************************************/
LCD_sendCommand_error LCD_8_bit_sendCommand(uint8_t u8_a_command);

/***************************************************************************/
/** @brief    Sends Characters to 8 bit mode LCD                           */
/** @param    u8_a_char                                                    */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_8_bit_sendChar(uint8_t u8_a_char);



/*                              4 bit mode                                 */

/***************************************************************************/
/** @brief  LCD 4 bit mode initialization function                         */
/** @param  void                                                           */
/** @return init_OK                                                        */
/***************************************************************************/
LCD_init_error LCD_4_bit_init(void);

/***************************************************************************/
/** @brief    Sends Commands to 4 bit mode LCD                             */
/** @param    u8_a_command   command to be sent to the LCD                 */
/** @return   cmnd_send_OK                                                 */
/***************************************************************************/
LCD_sendCommand_error LCD_4_bit_sendCommand(uint8_t u8_a_command);

/***************************************************************************/
/** @brief    Sends Characters to 4 bit mode LCD                           */
/** @param    u8_a_char                                                    */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_4_bit_sendChar(uint8_t u8_a_char);

/*                              Common                                     */

/***************************************************************************/
/** @brief    Sends string to LCD                                          */
/** @param    *u8_a_string                                                 */
/** @return   string_send_OK                                               */
/***************************************************************************/
LCD_sendString_error LCD_sendString(uint8_t *u8_a_string);

/***************************************************************************/
/** @brief    Go to a specific slot                                        */
/** @param    u8_a_row row number                                          */
/** @param    u8_a_coloumn column number                                   */
/** @return   void                                                         */
/***************************************************************************/
void LCD_goTo(uint8_t u8_a_row,uint8_t u8_a_column);

/***************************************************************************/
/** @brief    Creates a custom character                                   */
/** @param    u8_a_bitMap Character's bitmap                               */
/** @param    u8_a_location Characters' location in the memory             */
/** @return   void                                                         */
/***************************************************************************/
void LCD_createCustomCharacter(uint8_t *u8_a_bitMap,uint8_t u8_a_location);

/***************************************************************************/
/** @brief  LCD initialization function                                    */
/** @param  void                                                           */
/** @return init_OK                                                        */
/***************************************************************************/
LCD_init_error LCD_init(void);

/***************************************************************************/
/** @brief    Sends Commands LCD                                           */
/** @param    u8_a_command   command to be sent to the LCD                 */
/** @return   cmnd_send_OK                                                 */
/***************************************************************************/
LCD_sendCommand_error LCD_sendCommand(uint8_t u8_a_command);

/***************************************************************************/
/** @brief    Sends Characters LCD                                         */
/** @param    u8_a_char                                                    */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_sendChar(uint8_t u8_a_char);

#endif /*_INTERFACE_H_ */