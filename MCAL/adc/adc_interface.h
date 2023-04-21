/*
 * File: adc_interface.h
 * Created Date: Wednesday, April 19th 2023, 10:18:37 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
#include "../dio/dio.h"
#include "adc_private.h"


/***************************************************************************/
/** @brief   initializes the ADC                                           */
/** @param   u8_a_pinNumber  pin to initialize as an ADC input             */
/** @return  ADC_init_SUCCESS                                              */
/** @return  ADC_init_FAIL                                                 */
/***************************************************************************/
ADC_readError ADC_init(uint8_t u8_a_pinNumber);

/**************************************************************************************/
/** @brief   Reads the digital data from the adc and converts it to a digital value   */
/** @param   u8_a_pinNumber   pin to read                                             */
/** @param   *f_a_sensorValue refrence to store the read value in                     */
/** @return  ADC_read_SUCCESS                                                         */
/** @return  ADC_read_FAIL                                                            */
/**************************************************************************************/
ADC_readError ADC_read(uint8_t u8_a_pinNumber,float *f_a_sensorValue);

#endif /* ADC_INTERFACE_H */
