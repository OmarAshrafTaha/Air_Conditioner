/*
 * File: keypad.c
 * Created Date: Tuesday, April 18th 2023, 11:14:04 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */
#include "keypad_interface.h"

#define ROWS_SIZE 4
#define COLUMNS_SIZE 3
static uint8_t u8_gs_keypadMap[ROWS_SIZE][COLUMNS_SIZE] =
    {
        {BUTTON_1, BUTTON_2, BUTTON_3},
        {BUTTON_4, BUTTON_5, BUTTON_6},
        {BUTTON_7, BUTTON_8, BUTTON_9},
        {BUTTON_10, BUTTON_11, BUTTON_12}
    };

/***************************************************************************/
/** @brief  Keypad initialization                                          */
/** @param  void                                                           */
/** @return KEYPAD_initSuccess                                             */
/** @return KEYPAD_initFail                                                */
/***************************************************************************/
KEYPAD_initError KEYPAD_init(void)
{
    /*Rows direction initialization*/
    DIO_init(R1, ROW_PORT_DATA, OUTPUT);
    DIO_init(R2, ROW_PORT_DATA, OUTPUT);
    DIO_init(R3, ROW_PORT_DATA, OUTPUT);
    DIO_init(R4, ROW_PORT_DATA, OUTPUT);

    /*Columns direction initialization*/
    DIO_init(C1, COLUMN_PORT_DATA, INPUT);
    DIO_init(C2, COLUMN_PORT_DATA, INPUT);
    DIO_init(C3, COLUMN_PORT_DATA, INPUT);

    /*Initial pin values*/
#if CONNECTION == 'D'
    DIO_write(R1, ROW_PORT_DATA, LOW);
    DIO_write(R2, ROW_PORT_DATA, LOW);
    DIO_write(R3, ROW_PORT_DATA, LOW);
    DIO_write(R4, ROW_PORT_DATA, LOW);

#elif CONNECTION == 'U'
    DIO_write(R1, ROW_PORT_DATA, HIGH);
    DIO_write(R2, ROW_PORT_DATA, HIGH);
    DIO_write(R3, ROW_PORT_DATA, HIGH);
    DIO_write(R4, ROW_PORT_DATA, HIGH);

    DIO_write(C1, COLUMN_PORT_DATA, HIGH);
    DIO_write(C2, COLUMN_PORT_DATA, HIGH);
    DIO_write(C3, COLUMN_PORT_DATA, HIGH);

#endif
    return KEYPAD_initSuccess;
}

/***************************************************************************/
/** @brief Reads keypad strokes                                            */
/** @param *u8_a_value refrence to store the read value in                 */
/** @return KEYPAD_readSuccess                                             */
/** @return KEYPAD_readFail                                                */
/***************************************************************************/
KEYPAD_readError KEYPAD_read(uint8_t *u8_a_value)
{
    uint8_t i = 0;
    uint8_t j = 0;

#if CONNECTION == 'U'
#define u8_l_readCheck LOW
#define u8_l_pinValue LOW
#elif CONNECTION == 'D'
#define u8_l_readCheck HIGH
#define u8_l_pinValue HIGH
#endif

    uint8_t u8_l_Rows[ROWS_SIZE] = {R1, R2, R3, R4};
    uint8_t u8_l_Columns[COLUMNS_SIZE] = {C1, C2, C3};

    for (i = 0; i < ROWS_SIZE; i++)
    {
        DIO_write(u8_l_Rows[i], ROW_PORT_DATA, u8_l_pinValue);

        for (j = 0; j < COLUMNS_SIZE; j++)
        {
            DIO_read(u8_l_Columns[j], COLUMN_PORT_DATA, u8_a_value);
            if (*u8_a_value == u8_l_readCheck)
            {
                *u8_a_value = u8_gs_keypadMap[i][j];
                DIO_toggle(u8_l_Rows[i], ROW_PORT_DATA);
                return KEYPAD_readSuccess;
            }
        }
        DIO_toggle(u8_l_Rows[i], ROW_PORT_DATA);
    }
    return KEYPAD_readFail;
}