/*
 * File: main.c
 * Created Date: Sunday, April 16th 2023, 7:51:10 pm
 * Author: Omar Taha
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */
#include "ECUAL/lcd/lcd_interface.h"
uint8_t u8_g_bell[8] =   { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00};
uint8_t u8_g_bell_1[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x02, 0x00};
uint8_t u8_g_bell_2[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x01, 0x00, 0x08};
uint8_t u8_g_bell_3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x08, 0x00};
uint8_t u8_g_bell_4[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x10, 0x00, 0x08};			
int main(void)
{
    /* Replace with your application code */
 	//uint8_t val[] = "Hi! Omar";
	LCD_init();
	LCD_createCustomCharacter(u8_g_bell,0);
	LCD_createCustomCharacter(u8_g_bell_1,1);
	LCD_createCustomCharacter(u8_g_bell_2,2);
	LCD_createCustomCharacter(u8_g_bell_3,3);
	LCD_createCustomCharacter(u8_g_bell_4,4);			
	
	while(1)
	{
	LCD_goTo(0,8);	
	LCD_sendChar(0);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(1);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(2);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(1);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(0);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(3);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(4);
	TIMER0_delay(50);
	LCD_goTo(0,8);
	LCD_sendChar(3);
	TIMER0_delay(50);
	}

}
