/*
 * File: buzzer_interface.h
 * Created Date: Monday, April 24th 2023, 8:20:10 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

/***************************************************************************/
/** @brief Initialize buzzer as output                                     */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void BUZZ_init();

/***************************************************************************/
/** @brief Set buzzer pin as high                                          */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void BUZZ_on();

/***************************************************************************/
/** @brief  Set buzzer pin as low                                          */
/** @param  void                                                           */
/** @return void                                                           */
/***************************************************************************/
void BUZZ_off();

#endif /* BUZZER_INTERFACE_H_ */
