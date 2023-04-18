/*
 * File: lcd_private.h
 * Created Date: Monday, April 17th 2023, 2:47:14 am
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#include "lcd_config.h"

/*Macros for quick LCD Configurations*/
#define CGRAM              0x40
#define Cursor_Off         0x0C
#define Clear_Screen       0x01
#define LCD_4_Bit_Mode     0x02
#define LCD_8_Bit_Mode     0x38
#define Cursor_Blinking    0x0E
#define Cursor_Shift_Left  0x10
#define Cursor_Reset_Line1 0x80
#define Cursor_Reset_Line2 0xC0
#define Cursor_Shift_Right 0x06
#define LCD_4_Bit_Mode_5x7 0x28






/*Error types for LCD functions*/

/** @brief  enum for LCD status*/
typedef enum LCD_init_error
{
    init_OK,
    init_NOT_OK
} LCD_init_error;

/** @brief enum for LCD sending commands status*/
typedef enum LCD_sendCommand_error
{
    cmnd_send_OK,
    cmnd_send_NOT_OK
} LCD_sendCommand_error;

/** @brief enum for LCD sending character status*/
typedef enum LCD_sendString_error
{
	string_send_OK,
	string_send_NOT_OK
} LCD_sendString_error;

/** @brief enum for LCD sending character status*/
typedef enum LCD_sendChar_error
{
	char_send_OK,
	char_send_NOT_OK
} LCD_sendChar_error;


/*Checks which port is chosen*/

#if (LCD_Command_Port == 'A')
	#undef  LCD_Command_Port
	#define LCD_Command_Port PORTA
	#define LCD_Command_Dir DDRA

#elif (LCD_Command_Port == 'B')
	#undef  LCD_Command_Port
	#define LCD_Command_Port PORTB
	#define LCD_Command_Dir DDRB

#elif (LCD_Command_Port == 'C')
	#undef  LCD_Command_Port
	#define LCD_Command_Port PORTC
	#define LCD_Command_Dir DDRC

#elif (LCD_Command_Port == 'D')
	#undef  LCD_Command_Port
	#define LCD_Command_Port PORTD
	#define LCD_Command_Dir DDRD
#endif


/*Checks which port is chosen*/
#if (LCD_Data_Port == 'A')
	#undef  LCD_Data_Port
	#define LCD_Data_Port PORTA
	#define LCD_Data_Dir DDRA

#elif (LCD_Data_Port == 'B')
	#undef  LCD_Data_Port
	#define LCD_Data_Port PORTB
	#define LCD_Data_Dir DDRB

#elif (LCD_Data_Port == 'C')
	#undef  LCD_Data_Port
	#define LCD_Data_Port PORTC
	#define LCD_Data_Dir DDRC

#elif (LCD_Data_Port == 'D')
	#undef  LCD_Data_Port
	#define LCD_Data_Port PORTD
	#define LCD_Data_Dir DDRD
#endif
#endif /*_LCD_PRIVATE_H_ */
