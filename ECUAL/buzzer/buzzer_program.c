/*
 * File: buzzer_program.c
 * Created Date: Monday, April 24th 2023, 8:20:10 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */


/** INCLUDE LIBRARIES **/
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"

/** INCLUDE INTERFACE FILE OF LOWER LAYERS **/
#include "../../MCAL/dio/dio.h"

/** INCLUDE DRIVER FILES */
#include "buzzer_interface.h"
#include "buzzer_private.h"
#include "buzzer_config.h"



/***************************************************************************/
/** @brief Initialize buzzer as output                                     */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void BUZZ_init()
{
	/** SET THE DIRECTION OF BUZZER PIN AS OUTPUT **/
	DIO_init(BUZZ_PIN , BUZZ_PORT , OUTPUT);
}

/***************************************************************************/
/** @brief Set buzzer pin as high                                          */
/** @param void                                                            */
/** @return void                                                           */
/***************************************************************************/
void BUZZ_on()
{
	/** SET THE BUZZER PIN AS HIGH **/
	DIO_write(BUZZ_PIN , BUZZ_PORT , HIGH);
}


/***************************************************************************/
/** @brief  Set buzzer pin as low                                          */
/** @param  void                                                           */
/** @return void                                                           */
/***************************************************************************/
void BUZZ_off()
{
	/** SET THE BUZZER PIN AS LOW **/
	DIO_write(BUZZ_PIN , BUZZ_PORT , LOW);
}
