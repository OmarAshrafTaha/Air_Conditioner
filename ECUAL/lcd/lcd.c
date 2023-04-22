/*
 * File: lcd.c
 * Created Date: Monday, April 17th 2023, 1:21:26 am
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#include "lcd_interface.h"
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*                                                Custom Characters Bit Map                                                         */
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/

/*                              8 bit mode                                 */

/***************************************************************************/
/** @brief  LCD 8 bit mode initialization function                         */
/** @param  void                                                           */
/** @return init_OK                                                        */
/***************************************************************************/
LCD_init_error LCD_8_bit_init(void)
{
    Set_Bit(RS, LCD_Command_Dir);
    Set_Bit(RW, LCD_Command_Dir);
    Set_Bit(EN, LCD_Command_Dir);

    Set_mask(0xFF, LCD_Data_Dir);              /*LCD_Data_Port takes a whole port since 8 bit mode.*/
    TIMER0_delay(20);                          /*LCD power on delay is always >15 milliseconds*/
    LCD_8_bit_sendCommand(LCD_8_Bit_Mode);     /*Initialization of 16x2 LCD in 8 bit mode*/
    LCD_8_bit_sendCommand(Cursor_Off);      /*Display ON cursor OFF*/
	
    //LCD_8_bit_sendCommand(Cursor_Blinking);    /*Display ON cursor Blinking*/
    LCD_8_bit_sendCommand(Cursor_Shift_Right); /*Auto increment cursor*/
    LCD_8_bit_sendCommand(Clear_Screen);       /*Clear display*/
    LCD_8_bit_sendCommand(Cursor_Reset_Line1); /*Cursor at home position*/

#if LCD_Bit_Mode == 4
    return init_NOT_OK;
#elif LCD_Bit_Mode == 8
    return init_OK;
#endif
}

/***************************************************************************/
/** @brief    Sends Commands to 8 bit mode LCD                             */
/** @param    u8_a_command   command to be sent to the LCD                 */
/** @return   cmnd_send_OK                                                 */
/***************************************************************************/
LCD_sendCommand_error LCD_8_bit_sendCommand(uint8_t u8_a_command)
{
    LCD_Data_Port = u8_a_command;    /*Add command value to data port*/
    Clear_Bit(RS, LCD_Command_Port); /*RS = 0, Choose Command Register*/
    Clear_Bit(RW, LCD_Command_Port); /*RW = 0, Choose to write*/

    /*Generate a high to low pulse to the enable pin for a minimum of 450 nanoseconds*/
    Set_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.001);
    Clear_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.003);

    return cmnd_send_OK;
}

/***************************************************************************/
/** @brief    Sends Characters to 8 bit mode LCD                           */
/** @param    u8_a_char                                                    */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_8_bit_sendChar(uint8_t u8_a_char)
{
    LCD_Data_Port = u8_a_char;
    Set_Bit(RS, LCD_Command_Port);   /*RS = 1, Choose Data Register*/
    Clear_Bit(RW, LCD_Command_Port); /*RW = 0, Choose to Write*/

    /*Generate a high to low pulse to the enable pin for a minimum of 450 nanoseconds*/
    Set_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.001);
    Clear_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.003);
    return char_send_OK;
}

/*                              4 bit mode                                 */

/***************************************************************************/
/** @brief  LCD 4 bit mode initialization function                         */
/** @param  void                                                           */
/** @return init_OK                                                        */
/***************************************************************************/
LCD_init_error LCD_4_bit_init(void)
{
    Set_Bit(RS, LCD_Command_Dir);
    Set_Bit(RW, LCD_Command_Dir);
    Set_Bit(EN, LCD_Command_Dir);

    #if LCD_Data_Port_Nibble == 'U'
    Set_mask(0xF0, LCD_Data_Dir); /*Upper nibble of the port as output.*/
    #elif LCD_Data_Port_Nibble == 'L'
    Set_mask(0x0F, LCD_Data_Dir); /*Lower nibble of the port as output.*/
    #endif

    TIMER0_delay(20);                          /*LCD power on delay is always >15 milliseconds*/
    LCD_4_bit_sendCommand(LCD_4_Bit_Mode);     /*Initialization of 16x2 LCD in 8 bit mode*/
    LCD_4_bit_sendCommand(LCD_4_Bit_Mode_5x7); /*2 line 5x7 matrix in 4 bit mode*/
    LCD_4_bit_sendCommand(Cursor_Off);      /*Display ON cursor OFF*/
    //LCD_4_bit_sendCommand(Cursor_Blinking);    /*Display ON cursor Blinking*/
    LCD_4_bit_sendCommand(Cursor_Shift_Right); /*Auto increment cursor*/
    LCD_4_bit_sendCommand(Clear_Screen);       /*Clear display*/
    LCD_4_bit_sendCommand(Cursor_Reset_Line1); /*Cursor at home position*/

    #if LCD_Bit_Mode == 8
    return init_NOT_OK;
    #elif LCD_Bit_Mode == 4
    return init_OK;
    #endif
}

/***************************************************************************/
/** @brief    Sends Commands to 4 bit mode LCD                             */
/** @param    u8_a_command   command to be sent to the LCD                 */
/** @return   cmnd_send_OK                                                 */
/***************************************************************************/
LCD_sendCommand_error LCD_4_bit_sendCommand(uint8_t u8_a_command)
{
    #if LCD_Data_Port_Nibble == 'U'
    LCD_Data_Port = (LCD_Data_Port & 0x0F) | ((u8_a_command & 0xF0)); /*Add command value to data port, sending upper nibble*/
    #elif LCD_Data_Port_Nibble == 'L'
    LCD_Data_Port = (LCD_Data_Port & 0xF0) | ((u8_a_command & 0xF0) >> 4);
    #endif

    Clear_Bit(RS, LCD_Command_Port); /*RS = 0, Choose Command Register*/
    Clear_Bit(RW, LCD_Command_Port); /*RW = 0, Choose to write*/

    /*Generate a high to low pulse to the enable pin for a minimum of 450 nanoseconds*/
    Set_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.001);
    Clear_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.2);

    #if LCD_Data_Port_Nibble == 'U'
    LCD_Data_Port = (LCD_Data_Port & 0x0F) | ((u8_a_command & 0x0F) << 4); /*Add command value to data port, sending lower nibble*/
    #elif LCD_Data_Port_Nibble == 'L'
    LCD_Data_Port = (LCD_Data_Port & 0xF0) | ((u8_a_command & 0x0F));
    #endif

    /*Generate a high to low pulse to the enable pin for a minimum of 450 nanoseconds*/
    Set_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.001);
    Clear_Bit(EN, LCD_Command_Port);
    TIMER0_delay(2);

    return cmnd_send_OK;
}

/***************************************************************************/
/** @brief    Sends Characters to 4 bit mode LCD                           */
/** @param    u8_a_char                                                    */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_4_bit_sendChar(uint8_t u8_a_char)
{
    #if LCD_Data_Port_Nibble == 'U'
    LCD_Data_Port = (LCD_Data_Port & 0x0F) | ((u8_a_char & 0xF0));      /*Add data value to data port, sending upper nibble*/
    #elif LCD_Data_Port_Nibble == 'L'
    LCD_Data_Port = (LCD_Data_Port & 0xF0) | ((u8_a_char & 0xF0) >> 4);
    #endif

    Set_Bit(RS, LCD_Command_Port);   /*RS = 1, Choose Data Register*/
    Clear_Bit(RW, LCD_Command_Port); /*RW = 0, Choose to write*/

    /*Generate a high to low pulse to the enable pin for a minimum of 450 nanoseconds*/
    Set_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.001);
    Clear_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.2);
    #if LCD_Data_Port_Nibble == 'U'
    LCD_Data_Port = (LCD_Data_Port & 0x0F) | ((u8_a_char & 0x0F) << 4);/*Add data value to data port, sending lower nibble*/
    #elif LCD_Data_Port_Nibble == 'L'
    LCD_Data_Port = (LCD_Data_Port & 0xF0) | ((u8_a_char & 0x0F));
    #endif

    /*Generate a high to low pulse to the enable pin for a minimum of 450 nanoseconds*/
    Set_Bit(EN, LCD_Command_Port);
    TIMER0_delay(0.001);
    Clear_Bit(EN, LCD_Command_Port);
    TIMER0_delay(2);

    return char_send_OK;
}

/*                              Common                                     */

/***************************************************************************/
/** @brief    Sends string to 8 bit mode LCD                               */
/** @param    *u8_a_string                                                 */
/** @return   string_send_OK                                               */
/***************************************************************************/
LCD_sendString_error LCD_sendString(uint8_t *u8_a_string)
{
    uint16_t u16_l_charCount;
    for (u16_l_charCount = 0; u8_a_string[u16_l_charCount] != 0; u16_l_charCount++)
    {
        #if LCD_Bit_Mode == 8
        LCD_8_bit_sendChar(u8_a_string[u16_l_charCount]);

        #elif LCD_Bit_Mode == 4
        LCD_4_bit_sendChar(u8_a_string[u16_l_charCount]);
        #endif
    }
    return string_send_OK;
}

/***************************************************************************/
/** @brief    Go to a specific slot                                        */
/** @param    u8_a_row row number                                          */
/** @param    u8_a_coloumn column number                                   */
/** @return   void                                                         */
/***************************************************************************/
void LCD_goTo(uint8_t u8_a_row,uint8_t u8_a_column)
{
	uint8_t u8_l_rows[]={Cursor_Reset_Line1,Cursor_Reset_Line2};
    #if LCD_Bit_Mode == 8
    LCD_8_bit_sendCommand(u8_l_rows[u8_a_row]+u8_a_column);

    #elif LCD_Bit_Mode == 4
    LCD_4_bit_sendCommand(u8_l_rows[u8_a_row]+u8_a_column);
    #endif	
}

/***************************************************************************/
/** @brief    Creates a custom character                                   */
/** @param    *u8_a_bitMap Character's bitmap                              */
/** @param    u8_a_location Characters' location in the memory             */
/** @return   void                                                         */
/***************************************************************************/
void LCD_createCustomCharacter(uint8_t *u8_a_bitMap,uint8_t u8_a_location)
{
    uint8_t u8_l_count=0;

    #if LCD_Bit_Mode == 8
    LCD_8_bit_sendCommand( 0x40 + (u8_a_location*8) );

    for(u8_l_count=0 ; u8_l_count < 8 ;u8_l_count++)
    {
        LCD_8_bit_sendChar(u8_a_bitMap[u8_l_count]);
    }
    #elif LCD_Bit_Mode == 4
    LCD_4_bit_sendCommand(CGRAM+(u8_a_location*8));

    for(u8_l_count=0;u8_l_count < 8;u8_l_count++)
    {
        LCD_4_bit_sendChar(u8_a_bitMap[u8_l_count]);
    }
    #endif	
}

/***************************************************************************/
/** @brief  LCD initialization function                                    */
/** @param  void                                                           */
/** @return init_OK                                                        */
/***************************************************************************/
LCD_init_error LCD_init(void)
{
	#if LCD_Bit_Mode == 4
	LCD_4_bit_init();
	#elif LCD_Bit_Mode == 8
	LCD_8_bit_init();
	#endif
	
	return init_OK;
}

/***************************************************************************/
/** @brief    Sends Commands LCD                                           */
/** @param    u8_a_command   command to be sent to the LCD                 */
/** @return   cmnd_send_OK                                                 */
/***************************************************************************/
LCD_sendCommand_error LCD_sendCommand(uint8_t u8_a_command)
{
	#if LCD_Bit_Mode == 4
	LCD_4_bit_sendCommand(u8_a_command);
	#elif LCD_Bit_Mode == 8
	LCD_8_bit_sendCommand(u8_a_command);
	#endif
	
	return cmnd_send_OK;
}

/***************************************************************************/
/** @brief    Sends Characters LCD                                         */
/** @param    u8_a_char                                                    */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_sendChar(uint8_t u8_a_char)
{
	#if LCD_Bit_Mode == 4
	LCD_4_bit_sendChar(u8_a_char);
	#elif LCD_Bit_Mode == 8
	LCD_8_bit_sendChar(u8_a_char);
	#endif
    
	return char_send_OK;
}

/***************************************************************************/
/** @brief    Sends numbers to LCD                                         */
/** @param    f_a_number                                                   */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_sendFloat(float f_a_number)
{   
    uint16_t u_l_toString[10];
    uint8_t i =0;
    uint8_t j =0;

	uint16_t decimalPart;
	
	decimalPart=f_a_number*10;
	decimalPart=decimalPart % 10;
    if(f_a_number>0 && f_a_number < 1)
	{
		LCD_sendChar('0');
		if((int) decimalPart == 0)
		{
			LCD_sendChar('.');
			LCD_sendChar('0');
			return char_send_OK;
		}
	}
	else if(f_a_number == 0)
	{
		LCD_sendChar('0');
	}
	
	else
	{
		while( (int)f_a_number >= 1)
		{
			u_l_toString[i]=((int)f_a_number % 10) +48;
			f_a_number/=10;
			i++;
		}
		for(j=i; j > 0; j--)
		{
				LCD_sendChar(u_l_toString[j-1]);
		}
	}

	LCD_sendChar('.');
	LCD_sendChar(decimalPart+48);
    return char_send_OK;
}

/***************************************************************************/
/** @brief    Sends an integer value to LCD                                */
/** @param    u16_a_number                                                 */
/** @return   char_send_OK                                                 */
/***************************************************************************/
LCD_sendChar_error LCD_sendInteger(uint16_t u16_a_number)
{
	uint16_t u_l_toString[10];
	uint8_t i =0;
	uint8_t j =0;
	
	if(u16_a_number == 0)
	{
		LCD_sendChar('0');
	}
	while( u16_a_number > 0)
	{
		u_l_toString[i]=(u16_a_number % 10) +48;
		u16_a_number/=10;
		i++;
	}
	for(j=i; j > 0; j--)
	{
		LCD_sendChar(u_l_toString[j-1]);
	}
	return char_send_OK;
}