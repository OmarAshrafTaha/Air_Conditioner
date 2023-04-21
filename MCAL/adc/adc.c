/*
 * File: adc.c
 * Created Date: Wednesday, April 19th 2023, 10:18:43 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */
#include "adc_interface.h"

#define VREF 5.0
#define ADC_STEP VREF/1024.0


/***************************************************************************/
/** @brief   initializes the ADC                                           */
/** @param   u8_a_pinNumber  pin to initialize as an ADC input             */
/** @return  ADC_init_SUCCESS                                              */
/** @return  ADC_init_FAIL                                                 */
/***************************************************************************/
ADC_readError ADC_init(uint8_t u8_a_pinNumber)
{

    DIO_init(u8_a_pinNumber,ADC_PORT,INPUT);
    
    /*Setting the voltage reference selection*/
    #if   VOLTAGE_REFERENCE == 'A'
    Clear_Bit(6,ADMUX);
    Clear_Bit(7,ADMUX);
    #elif VOLTAGE_REFERENCE == 'B'
    Set_Bit(6,ADMUX);
    #elif VOLTAGE_REFERENCE == 'C'
    Set_Bit(6,ADMUX);
    Set_Bit(7,ADMUX);
    #endif

    /*Setting the ADMUX to Left or Right adjustment*/
    #if   ADJUST_DIRECTION == 'L'
    Set_Bit(5,ADMUX);
    #elif ADJUST_DIRECTION == 'R'
    Clear_Bit(5,ADMUX);
    #endif

    //ADMUX |= (u8_a_pinNumber & 0x0F); /*Setting the ADMUX single ended channel on the chosen channel/pin */

    Set_Bit(7,ADCSRA);       /*Enabling the ADC*/

    #if   ENABLE_INTERRUPT == 'Y'
    Set_Bit(3,ADCSRA);
    #elif ENABLE_INTERRUPT == 'N'
    Clear_Bit(3,ADCSRA);
    #endif

    #if   ADC_PRESCALER == 2
    ADCSRA |= 0x00;
    #elif ADC_PRESCALER == 4
    ADCSRA |= 0x02;
    #elif ADC_PRESCALER == 8
    ADCSRA |= 0x03;    
    #elif ADC_PRESCALER == 16
    ADCSRA |= 0x04;    
    #elif ADC_PRESCALER == 32
    ADCSRA |= 0x05;    
    #elif ADC_PRESCALER == 64
    ADCSRA |= 0x06;    
    #elif ADC_PRESCALER == 128
    ADCSRA |= 0x07;    
    #endif
	
	return ADC_init_SUCCESS;
}

/**************************************************************************************/
/** @brief   Reads the digital data from the adc and converts it to a digital value   */
/** @param   u8_a_pinNumber   pin to read                                             */
/** @param   *f_a_sensorValue refrence to store the read value in                     */
/** @return  ADC_read_SUCCESS                                                         */
/** @return  ADC_read_FAIL                                                            */
/**************************************************************************************/
ADC_readError ADC_read(uint8_t u8_a_pinNumber,float *f_a_sensorValue)
{
    uint16_t u16_l_digitalValue = 0;
    float    u16_l_analogValue  = 0;
    uint16_t u16_l_tempValue    = 0;

    ADMUX |= (u8_a_pinNumber & 0x0F); /*Setting the ADMUX single ended channel on the chosen channel/pin */
    Set_Bit(6,ADCSRA);
    while( ( ADCSRA & (1<<4) ) == 0);

    #if   ADJUST_DIRECTION == 'L'
    u16_l_digitalValue = (ADCL>>6) | (ADCH<<2);
    #elif ADJUST_DIRECTION == 'R'
    u16_l_digitalValue = ADCL | (ADCH<<8);
    #endif

    u16_l_analogValue  = u16_l_digitalValue * ADC_STEP;
    *f_a_sensorValue = u16_l_analogValue / SENSOR_RESOLUTION;
	
	return ADC_read_SUCCESS;
}