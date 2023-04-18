/*
 * timers.h
 *
 * Created: 4/8/2023 4:39:45 PM
 *  Author: Omar Taha
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../MCAL/interrupts/interrupts.h"
#include <math.h>

#define  TIMER_OFF_    0
#define  NO_PRESCALE_  1
#define  PRESCALE_8_   8
#define  PRESCALE_64_  64
#define  PRESCALE_256_ 256
#define	 PRESCALE_1024_ 1024
#define  PRESCALE_EXT_FALLING_ 11
#define  PRESCALE_EXT_RISING_ 12

/************************************************************************/
/*Choose a prescaler mode from this list => TIMER_OFF_                  */
/*										 =>	NO_PRESCALE_			    */
/*										 => PRESCALE_8_					*/
/*										 => PRESCALE_64_				*/
/*										 => PRESCALE_256_				*/
/*										 => PRESCALE_1024_				*/
/*										 => PRESCALE_EXT_FALLING_		*/
/*										 => PRESCALE_EXT_RISING_        */
/************************************************************************/
#define F_CPU 1000000.0 //1Mhz
#define PRESCALER_MODE NO_PRESCALE_
#define t_tick  ((float)(PRESCALER_MODE / F_CPU))
#define t0_max_delay  (256.0 * t_tick)
#define t2_max_delay  (256.0 * t_tick)

/************************************************************************/
/* Timer 0 driver							                            */
/************************************************************************/

/********************************************************************************************/
/*Description: Set timer 0 control register to normal mode by clearing bits COM00 & COM01.  */
/*@param void                                                                               */	
/********************************************************************************************/
err_state TIMER0_normalMode(void);

/****************************************************************************************/
/*Description: Setting the initial value for the timer 0 counter register               */
/*@param value initial value to start timer 0 from                                      */	
/****************************************************************************************/
err_state TIMER0_initialValue(uint8_t value);

/************************************************************************/
/*Description: Sets the prescaler mode.                                 */
/*Choose a prescaler mode from this list => TIMER_OFF_                  */
/*                                       => NO_PRESCALE_                */
/*                                       => PRESCALE_8_	                */
/*                                       => PRESCALE_64_                */
/*                                       => PRESCALE_256_               */
/*                                       => PRESCALE_1024_              */
/*                                       => PRESCALE_EXT_FALLING_       */
/*                                       => PRESCALE_EXT_RISING_        */
/*@param prescaler prescaler mode                                       */	
/************************************************************************/
err_state TIMER0_prescalerMode(unsigned int u16_a_prescaler);

/************************************************************************/
/*Description: Stays in a busy loop until the delay is met              */
/*@param f_a_delayInMillis  delay time needed in ms                     */	
/************************************************************************/
err_state TIMER0_delay(float f_a_delayInMillis);

/************************************************************************************************************************************************************************/
/*Description: Gets The timer initial value according to the delay needed, prescaler mode and CPU frequency, then sets the timer initial value accordingly.             */
/*@param f_a_delayInMillis delay time needed in ms                                                                                                                      */
/************************************************************************************************************************************************************************/
unsigned int TIMER0_getInitialValue(float f_a_delayInMillis);





/************************************************************************/
/* Timer 2 driver							                            */
/************************************************************************/

/********************************************************************************************/
/*Description: Set timer 2 control register to normal mode by clearing bits COM00 & COM01.  */
/*@param void                                                                               */	
/********************************************************************************************/
err_state TIMER2_normalMode(void);

/****************************************************************************************/
/*Description: Setting the initial value for the timer 2 counter register               */
/*@param value initial value to start timer 2 from                                      */
/****************************************************************************************/
err_state TIMER2_initialValue(uint8_t value);

/************************************************************************/
/*Description: Sets the prescaler mode.                                 */
/*Choose a prescaler mode from this list => TIMER_OFF_                  */
/*                                       => NO_PRESCALE_                */
/*                                       => PRESCALE_8_	                */
/*                                       => PRESCALE_64_                */
/*                                       => PRESCALE_256_               */
/*                                       => PRESCALE_1024_              */
/*                                       => PRESCALE_EXT_FALLING_       */
/*                                       => PRESCALE_EXT_RISING_        */
/*@param prescaler prescaler mode                                       */	
/************************************************************************/
err_state TIMER2_perscalerMode(unsigned int u16_a_prescaler);

/************************************************************************/
/*Description: Stays in a busy loop until the delay is met              */
/*@param f_a_delayInMillis delay time needed in ms                      */
/************************************************************************/
err_state TIMER2_delay(float f_a_delayInMillis);

/************************************************************************************************************************************************************************/
/*Description: Gets The timer initial value according to the delay needed, prescaler mode and CPU frequency, then sets the timer initial value accordingly.             */
/*@param f_a_delayInMillis delay time needed in ms                                                                                                                      */
/************************************************************************************************************************************************************************/
unsigned int TIMER2_getInitialValue(float f_a_delayInMillis);


void set_TIMER2_OVF_callBack(void (*callback)(void));

#endif /* TIMERS_H_ */