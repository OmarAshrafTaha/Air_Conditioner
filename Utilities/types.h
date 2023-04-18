/*
 * types.h
 *
 * Created: 4/5/2023 3:35:04 PM
 *  Author: Omar Taha
 */ 


#ifndef TYPES_H_
#define TYPES_H_
#define nullPtr ((void*)0)

typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;

typedef enum err_state
{
	SUCCESS,FAIL
}err_state;
typedef enum pin_dir
{
	INPUT,OUTPUT
}pin_dir;

typedef enum pin_state
{
	LOW,HIGH
}pin_state;



#endif /* TYPES_H_ */