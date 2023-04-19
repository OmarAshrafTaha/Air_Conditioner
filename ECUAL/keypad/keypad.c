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


/***************************************************************************/
/** @brief  Keypad initialization                                          */
/** @param  void                                                           */
/** @return KEYPAD_initSuccess                                             */
/** @return KEYPAD_initFail                                                */
/***************************************************************************/
KEYPAD_initError KEYPAD_init(void)
{
    /*Rows initialization*/
    DIO_init(R1,ROW_PORT_DATA,OUTPUT);
    DIO_init(R2,ROW_PORT_DATA,OUTPUT);
    DIO_init(R3,ROW_PORT_DATA,OUTPUT);
    DIO_init(R4,ROW_PORT_DATA,OUTPUT);

    DIO_write(R1,ROW_PORT_DATA,HIGH);
    DIO_write(R2,ROW_PORT_DATA,HIGH);
    DIO_write(R3,ROW_PORT_DATA,HIGH);
    DIO_write(R4,ROW_PORT_DATA,HIGH);

// 	DIO_write(R1,ROW_PORT_DATA,LOW);
// 	DIO_write(R2,ROW_PORT_DATA,LOW);
// 	DIO_write(R3,ROW_PORT_DATA,LOW);
// 	DIO_write(R4,ROW_PORT_DATA,LOW);
	
    /*Columns initialization*/
    DIO_init(C1,COLUMN_PORT_DATA,INPUT);
    DIO_init(C2,COLUMN_PORT_DATA,INPUT);
    DIO_init(C3,COLUMN_PORT_DATA,INPUT);

    DIO_write(C1,COLUMN_PORT_DATA,HIGH);
    DIO_write(C2,COLUMN_PORT_DATA,HIGH);
    DIO_write(C3,COLUMN_PORT_DATA,HIGH);

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
    uint8_t u8_l_Rows[ROWS_SIZE] = {R1,R2,R3,R4};
    uint8_t u8_l_Columns[COLUMNS_SIZE] = {C1,C2,C3};
    for (i = 0; i < ROWS_SIZE; i++)
    {
        DIO_write(u8_l_Rows[i],ROW_PORT_DATA,LOW);

        for(j = 0; j < COLUMNS_SIZE; j++)
        {
            DIO_read(u8_l_Columns[j],COLUMN_PORT_DATA,u8_a_value);
            if (*u8_a_value == 0)
            {
                if (i == 0)
                {
                    if(j == 0)
                    {
                        *u8_a_value = '1';
                    }
                    else if(j==1)
                    {
                        *u8_a_value = '2';
                    }
                    else if(j==2)
                    {
                        *u8_a_value = '3';
                    }
                }

                else if (i == 1)
                {
                    if(j == 0)
                    {
                        *u8_a_value = '4';
                    }
                    else if(j==1)
                    {
                        *u8_a_value = '5';
                    }
                    else if(j==2)
                    {
                        *u8_a_value = '6';
                    }
                }

                else if (i == 2)
                {
                    if(j == 0)
                    {
                        *u8_a_value = '7';
                    }
                    else if(j==1)
                    {
                        *u8_a_value = '8';
                    }
                    else if(j==2)
                    {
                        *u8_a_value = '9';
                    }
                }

                else if (i == 3)
                {
                    if(j == 0)
                    {
                        *u8_a_value = '*';
                    }
                    else if(j==1)
                    {
                        *u8_a_value = '0';
                    }
                    else if(j==2)
                    {
                        *u8_a_value = '#';
                    }
                }
			    DIO_write(u8_l_Rows[i],ROW_PORT_DATA,HIGH);	                
				return KEYPAD_readSuccess;
            }  
        }
	DIO_write(u8_l_Rows[i],ROW_PORT_DATA,HIGH);
	}
    return KEYPAD_readFail;
}