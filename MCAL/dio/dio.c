/*
 * dio.c
 *
 * Created: 4/5/2023 3:53:56 PM
 *  Author: Omar Taha
 */ 
#include "dio.h"

/*******************************************************************************************/
/*Description: Initialize a pin as output or input depending on the direction passed       */
/*@param u8_l_pinNumber     pin number                                                     */
/*@param u8_l_portNumber    port number                                                    */
/*@param en_l_direction     direction                                                      */
/*******************************************************************************************/
err_state DIO_init(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber, pin_dir en_l_direction)  
{
    switch(u8_l_portNumber)
    {
        case PORT_A:
            if(en_l_direction == INPUT)
            {
                Clear_Bit(u8_l_pinNumber,DDRA);
            }
            else if(en_l_direction == OUTPUT)
            {
                Set_Bit(u8_l_pinNumber,DDRA);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
            
        case PORT_B:
            if(en_l_direction == INPUT)
            {
                Clear_Bit(u8_l_pinNumber,DDRB);
            }
            else if(en_l_direction == OUTPUT)
            {
                Set_Bit(u8_l_pinNumber,DDRB);			
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
            
        case PORT_C:
            if(en_l_direction == INPUT)
            {
                Clear_Bit(u8_l_pinNumber,DDRC);				
            }
            else if(en_l_direction == OUTPUT)
            {
                Set_Bit(u8_l_pinNumber,DDRC);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
            
        case PORT_D:
            if(en_l_direction == INPUT)
            {
                Clear_Bit(u8_l_pinNumber,DDRD);			
            }
            else if(en_l_direction == OUTPUT)
            {
                Set_Bit(u8_l_pinNumber,DDRD);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
            
        default:
            return FAIL;		
    }
    return SUCCESS;
}


/*******************************************************************************************/
/*Description: Sets a pin as HIGH or LOW depending on the state passed                     */
/*@param u8_l_pinNumber      pin number                                                    */
/*@param u8_l_portNumber     port number                                                   */
/*@param en_l_value          pin desired state                                             */
/*******************************************************************************************/
err_state DIO_write(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber, pin_state en_l_value)   
{	
    switch(u8_l_portNumber)
    {
        case PORT_A:
            if(en_l_value == LOW)
            {
                Clear_Bit(u8_l_pinNumber,PORTA);
            }
            else if(en_l_value == HIGH)
            {
                Set_Bit(u8_l_pinNumber,PORTA);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        case PORT_B:
            if(en_l_value == LOW)
            {
                Clear_Bit(u8_l_pinNumber,PORTB);
            }
            else if(en_l_value == HIGH)
            {
                Set_Bit(u8_l_pinNumber,PORTB);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        case PORT_C:
            if(en_l_value == LOW)
            {
                Clear_Bit(u8_l_pinNumber,PORTC);
            }
            else if(en_l_value == HIGH)
            {
                Set_Bit(u8_l_pinNumber,PORTC);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        case PORT_D:
            if(en_l_value == LOW)
            {
                Clear_Bit(u8_l_pinNumber,PORTD);
            }
            else if(en_l_value == HIGH)
            {
                Set_Bit(u8_l_pinNumber,PORTD);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        default:
            return FAIL;
    }
    return SUCCESS;
}

/*******************************************************************************************/
/*Description: Sets an array of pins as HIGH or LOW depending on the state passed          */
/*@param u8_l_mask              pins mask                                                  */
/*@param u8_l_portNumber        port number                                                */
/*@param en_l_value             mask desired state                                         */
/*******************************************************************************************/
err_state DIO_array_write(uint8_t u8_l_mask, uint8_t u8_l_portNumber, pin_state en_l_value)   
{
    switch(u8_l_portNumber)
    {
        case PORT_A:
            if(en_l_value == LOW)
            {
                Clear_mask(u8_l_mask,PORTA);
            }
            else if(en_l_value == HIGH)
            {
                Set_mask(u8_l_mask,PORTA);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        case PORT_B:
            if(en_l_value == LOW)
            {
                Clear_mask(u8_l_mask,PORTB);
            }
            else if(en_l_value == HIGH)
            {
                Set_mask(u8_l_mask,PORTB);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        case PORT_C:
            if(en_l_value == LOW)
            {
                Clear_mask(u8_l_mask,PORTC);
            }
            else if(en_l_value == HIGH)
            {
                Set_mask(u8_l_mask,PORTC);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        case PORT_D:
            if(en_l_value == LOW)
            {
                Clear_mask(u8_l_mask,PORTD);
            }
            else if(en_l_value == HIGH)
            {
                Set_mask(u8_l_mask,PORTD);
            }
            else
            {
                // Error Handling
                return FAIL;
            }
            break;
        
        default:
            return FAIL;
    }
    return SUCCESS;
}

/*******************************************************************************************/
/*Description: Toggles a pin state                                                         */
/*@param u8_l_pinNumber        pin number                                                  */
/*@param u8_l_portNumber       port number                                                 */
/*******************************************************************************************/
err_state DIO_toggle(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber)					
{
    switch(u8_l_portNumber)
    {
        case PORT_A:
            Toggle_Bit(u8_l_pinNumber,PORTA);
            break;

        case PORT_B:
            Toggle_Bit(u8_l_pinNumber,PORTB);
            break;
            
        case PORT_C:
            Toggle_Bit(u8_l_pinNumber,PORTC);
            break;
            
        case PORT_D:
            Toggle_Bit(u8_l_pinNumber,PORTD);
            break;
        default:
            //Error handling
            return FAIL;						
    }
    return SUCCESS;
}

/*******************************************************************************************/
/*Description: Reads a pin state                                                           */
/*@param u8_l_pinNumber          pin number                                                */
/*@param u8_l_portNumber         port number                                               */
/*@param *en_l_value             refrence to store the read state in                       */
/*******************************************************************************************/
err_state DIO_read(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber, pin_state *en_l_value)   
{
    switch(u8_l_portNumber)
    {
        case PORT_A:
            *en_l_value = Read_Bit(u8_l_pinNumber,PINA);
            break;

        case PORT_B:
            *en_l_value = Read_Bit(u8_l_pinNumber,PINB);
            break;
        
        case PORT_C:
            *en_l_value = Read_Bit(u8_l_pinNumber,PINC);
            break;
        
        case PORT_D:
            *en_l_value = Read_Bit(u8_l_pinNumber,PIND);			
            break;
        
        default:
            //Error handling
            return FAIL;
        
    }
    return SUCCESS;
}