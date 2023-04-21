/*
 * File: adc_private.h
 * Created Date: Wednesday, April 19th 2023, 10:18:28 pm
 * Author: Omar Taha
 * -----
 * Copyright (c) 2023 Omar Taha <<https://github.com/OmarAshrafTaha>>
 */

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "adc_config.h"
#define ADC_PORT PORT_A
#define ADLAR 5

typedef enum ADC_initError
{
    ADC_init_SUCCESS,ADC_init_FAIL
}ADC_initError;



typedef enum ADC_readError
{
    ADC_read_SUCCESS, ADC_read_FAIL
}ADC_readError;


#endif /* ADC_PRIVATE_H */
