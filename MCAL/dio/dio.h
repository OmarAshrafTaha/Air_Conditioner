/*
 * dio.h
 *
 * Created: 4/5/2023 3:53:43 PM
 *  Author: Omar Taha
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

/*******************************************************************************************/
/*Description: Initialize a pin as output or input depending on the direction passed       */
/*@param u8_l_pinNumber      pin number                                                    */
/*@param u8_l_portNumber     port number                                                   */
/*@param en_l_direction      direction                                                     */
/*******************************************************************************************/
err_state DIO_init(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber, pin_dir en_l_direction);

/*******************************************************************************************/
/*Description: Sets a pin as HIGH or LOW depending on the state passed                     */
/*@param u8_l_pinNumber      pin number                                                    */
/*@param u8_l_portNumber     port number                                                   */
/*@param en_l_value          pin desired state                                             */
/*******************************************************************************************/
err_state DIO_write(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber, pin_state en_l_value);

/*******************************************************************************************/
/*Description: Toggles a pin state                                                         */
/*@param u8_l_pinNumber        pin number                                                  */
/*@param u8_l_portNumber       port number                                                 */
/*******************************************************************************************/
err_state DIO_toggle(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber);	

/*******************************************************************************************/
/*Description: Reads a pin state                                                           */
/*@param u8_l_pinNumber          pin number                                                */
/*@param u8_l_portNumber         port number                                               */
/*@param *en_l_value             refrence to store the read state in                       */
/*******************************************************************************************/
err_state DIO_read(uint8_t u8_l_pinNumber, uint8_t u8_l_portNumber, pin_state *en_l_value);

/*******************************************************************************************/
/*Description: Sets an array of pins as HIGH or LOW depending on the state passed          */
/*@param u8_l_mask              pins mask                                                  */
/*@param u8_l_portNumber        port number                                                */
/*@param en_l_value             mask desired state                                         */
/*******************************************************************************************/
err_state DIO_array_write(uint8_t u8_l_mask, uint8_t u8_l_portNumber, pin_state en_l_value);

#endif /* DIO_H_ */