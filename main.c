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

#include "APP/app.h"

int main(void)
{
    /* Replace with your application code */	
    LCD_init();
    KEYPAD_init();
	ADC_init(7);
	APP_init();
	
    while (1)
    {
		APP_defaultView();
    }

}
