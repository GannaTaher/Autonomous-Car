/*
 * MD_Prog.c
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 *
 * Source file for the motor driver.
 *
 * This file contains the implementation of the motor driver functions.

 */
/*
 * Header file for Delay
 */
#include<util/delay.h>


/*
 * Header file that contains the standard data types & Errors
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERR_TYPE.h"


/*
 * Header file that contains bit manipulation macros.
 */
#include "../LIB/BIT_MATH.h"

/*
 * This header file contains the interface for DIO operations.
 */
#include "../DIO/DIO_interface.h"

/*
 * Header file that contains the interface for timer operations.
 */
#include "../TIMER/TIMER_interface.h"

/*
 * Header file that contains the interface for CLCD operations.
 */
#include "../CLCD/CLCD_interface.h"

/*
 *  Header file that contains the interface for the motor driver.
 */
#include "MD_interface.h"

/*
 * Header file that contains private definitions for the motor driver.
 */
#include "MD_Prv.h"

/*
 *  Header file that contains the configuration for the motor driver.
 */
#include "MD_cfg.h"


extern u8 MD_u8PreDuty;

void MotorDriver_voidInit(void)
{
	// Configure Control Pins for direction control

	DIO_u8SetPinDirection(MD_PORT,MD_INT1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(MD_PORT,MD_INT2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(MD_PORT,MD_INT3,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(MD_PORT,MD_INT4,DIO_u8PIN_OUTPUT);

	// Configure PWM channels for speed control
	TIMER0_voidInit();
	TIMER0_voidSetCompMatch(MAX_SPEED);

	TIMER2_voidInit();
	TIMER2_voidSetCompMatch(MAX_SPEED);

}

void MotorDriver_voidControlSpeed(u8 Copy_DutyCycle)
{
	Timer_PWM_Start(Copy_DutyCycle);
}

void MotorDriver_voidMoveForward(void)
{
	DIO_u8SetPinValue(MD_PORT,MD_INT1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(MD_PORT,MD_INT2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT3,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(MD_PORT,MD_INT4,DIO_u8PIN_LOW);

	MotorDriver_voidControlSpeed(MD_u8PreDuty);

}

void MotorDriver_voidMoveBackward(void)
{
	DIO_u8SetPinValue(MD_PORT,MD_INT1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(MD_PORT,MD_INT3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT4,DIO_u8PIN_HIGH);

	MotorDriver_voidControlSpeed(MD_u8PreDuty);

}

void MotorDriver_voidMoveRight(void)
{

	DIO_u8SetPinValue(MD_PORT,MD_INT1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(MD_PORT,MD_INT3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT4,DIO_u8PIN_LOW);

	MotorDriver_voidControlSpeed(MD_u8PreDuty);

}

void MotorDriver_voidMoveLeft(void)
{

	DIO_u8SetPinValue(MD_PORT,MD_INT1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT4,DIO_u8PIN_HIGH);

	MotorDriver_voidControlSpeed(MD_u8PreDuty);

}

void MotorDriver_voidStop(void)
{
	DIO_u8SetPinValue(MD_PORT,MD_INT1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MD_PORT,MD_INT4,DIO_u8PIN_LOW);


}
