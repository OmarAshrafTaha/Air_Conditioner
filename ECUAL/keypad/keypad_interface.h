/*
 * File: keypad_interface.h
 * Created Date: Tuesday, April 18th 2023, 11:14:27 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#include "../../Utilities/types.h"
#include "../../MCAL/dio/dio.h"
#include "keypad_config.h"
#include "keypad_private.h"

/***************************************************************************/
/** @brief  Keypad initialization                                          */
/** @param  void                                                           */
/** @return KEYPAD_initSuccess                                             */
/** @return KEYPAD_initFail                                                */
/***************************************************************************/
KEYPAD_initError KEYPAD_init(void);

/***************************************************************************/
/** @brief Reads keypad strokes                                            */
/** @param *u8_a_value refrence to store the read value in                 */
/** @return KEYPAD_readSuccess                                             */
/** @return KEYPAD_readFail                                                */
/***************************************************************************/
KEYPAD_readError KEYPAD_read(uint8_t *u8_a_value);

#endif /* KEYPAD_INTERFACE_H */
