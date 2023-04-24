/*
 * interrupts.c
 *
 * Created: 4/15/2023 3:39:36 AM
 *  Author: Omar Taha
 */ 
#include "interrupts.h"

void static (*EXT_INT_0_callBack) (void) = nullPtr;
void static (*EXT_INT_1_callBack) (void) = nullPtr;
void static (*EXT_INT_2_callBack) (void) = nullPtr;

void set_EXT_INT_0_callBack(void (*callback) (void))
{
	EXT_INT_0_callBack = callback;
}

void set_EXT_INT_1_callBack(void (*callback) (void))
{
	EXT_INT_1_callBack = callback;
}

void set_EXT_INT_2_callBack(void (*callback) (void))
{
	EXT_INT_2_callBack = callback;
}

ISR(EXT_INT_0)
{
	EXT_INT_0_callBack();
}

ISR(EXT_INT_1)
{
	EXT_INT_1_callBack();
}

ISR(EXT_INT_2)
{
	EXT_INT_2_callBack();
}



// void EXTINT_setCallBackInt (uint8_t u8_a_intNumber, void (*funPtr) (void))
// {
//  	if (funPtr != nullPtr)
// 	{
//  		if (u8_a_intNumber == INT_0)
//  		{
// 			EXTINT_0_callBack = funPtr;
//  		}
//  		else if (u8_a_intNumber == INT_1)
//  		{
// 			EXTINT_1_callBack = funPtr;
//  		}
//  		else if (u8_a_intNumber == INT_2)
//  		{
//  			EXTINT_2_callBack = funPtr;
//  		}
//

// }
/// 
// ISR(EXT_INT_0)
// {
// 	if (EXTINT_0_callBack != nullPtr)
// 	{
// 		EXTINT_0_callBack();
// 	}
// }

/*EXTINT_setCallBackInt(INT_2, APP_button1Task);*/