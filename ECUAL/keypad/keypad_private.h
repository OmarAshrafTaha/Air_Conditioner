/*
 * File: keypad_private.h
 * Created Date: Tuesday, April 18th 2023, 11:14:37 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef KEYPAD_PRIVATE_H
#define KEYPAD_PRIVATE_H
#include "keypad_config.h"

/*Keypad initialization error*/
typedef enum KEYPAD_initError
{
    KEYPAD_initSuccess,KEYPAD_initFail
}KEYPAD_initError;

/*Keypad read error*/
typedef enum KEYPAD_readError
{
    KEYPAD_readSuccess,KEYPAD_readFail
}KEYPAD_readError;


#if ROW_PORT == 'A'
#define ROW_PORT_DATA PORT_A
#elif ROW_PORT == 'B'
#define ROW_PORT_DATA PORT_B
#elif ROW_PORT == 'C'
#define ROW_PORT_DATA PORT_C
#elif ROW_PORT == 'D'
#define ROW_PORT_DATA PORT_D
#endif

#if COLUMN_PORT == 'A'
#define COLUMN_PORT_DATA PORT_A
#elif COLUMN_PORT == 'B'
#define COLUMN_PORT_DATA PORT_B
#elif COLUMN_PORT == 'C'
#define COLUMN_PORT_DATA PORT_C
#elif COLUMN_PORT == 'D'
#define COLUMN_PORT_DATA PORT_D
#endif

#endif /* KEYPAD_PRIVATE_H */
