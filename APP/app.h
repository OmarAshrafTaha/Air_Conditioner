/*
 * File: app.h
 * Created Date: Friday, April 21st 2023, 3:47:15 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef APP_H
#define APP_H
#include "../ECUAL/lcd/lcd_interface.h"
#include "../ECUAL/keypad/keypad_interface.h"
#include "../MCAL/adc/adc_interface.h"
#include "../ECUAL/buzzer/buzzer_interface.h"

typedef enum APP_initError
{
    APP_initSuccess,
    APP_initFail
} APP_initError;

/***************************************************************************/
/** @brief Initializes all application modules and sets global variables   */
/** @param void                                                            */
/** @return APP_initSuccess                                                */
/** @return APP_initFail                                                   */
/***************************************************************************/
APP_initError APP_init(void);

/***************************************************************************/
/** @brief Prints a string to the LCD                                      */
/** @param u8_a_row row to print into                                      */
/** @param u8_a_column column to print into                                */
/** @param u8_a_str string to be printed in the passed coordinates         */
/** @return void                                                           */
/***************************************************************************/
void APP_printString(uint8_t u8_a_row, uint8_t u8_a_column, uint8_t *u8_a_str);

/***************************************************************************/
/** @brief Prints a character to the LCD                                   */
/** @param u8_a_row row to print into                                      */
/** @param u8_a_column column to print into                                */
/** @param u8_a_char character to be printed in the passed coordinates     */
/** @return void                                                           */
/***************************************************************************/
void APP_printChar(uint8_t u8_a_row, uint8_t u8_a_column, uint8_t u8_a_char);

/***************************************************************************/
/** @brief Prints an integer to the LCD                                    */
/** @param u8_a_row row to print into                                      */
/** @param u8_a_column column to print into                                */
/** @param u8_a_integer integer to be printed in the passed coordinates    */
/** @return void                                                           */
/***************************************************************************/
void APP_printInteger(uint8_t u8_a_row, uint8_t u8_a_column, uint16_t u16_a_integer);

/***************************************************************************/
/** @brief Sets the required temprature by incrementing and decrementing   */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void APP_setTemp();

/***************************************************************************/
/** @brief Decrements the bar resembling the temprature value              */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void APP_decrementBar();

/***************************************************************************/
/** @brief Increments the bar resembling the temprature value              */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void APP_incrementBar();

/********************************************************************************************************************************************************/
/** @brief Shows the current and required temprature on the LCD while checking if the user wants to readjust the temp or reset it to its default value  */
/** @param void                                                                                                                                         */
/** @return void                                                                                                                                        */
/********************************************************************************************************************************************************/
void APP_defaultView(void);

/**********************************************************************************/
/** @brief Callback function for timer 2 ISR which increments with every overflow */
/** @param  void                                                                  */
/** @return void                                                                  */
/**********************************************************************************/
void get_current_overflow(void);
#endif /* APP_H */
