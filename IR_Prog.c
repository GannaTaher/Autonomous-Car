/*
 * IR_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: GANNA TAHER
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/ERR_TYPE.h"
#include "../LIB/BIT_MATH.h"

#include "IR_Prv.h"
#include "IR_Cfg.h"
#include "IR_interface.h"
#include "../MotorDriver/MD_interface.h"
#include "../DIO/DIO_interface.h"

extern u8 MD_u8PreDuty;

void IR_voidInit(void)
{

	DIO_u8SetPinDirection(IR_PORT,IR_PIN,DIO_u8PIN_INPUT);     //Receiver

	DIO_u8SetPinValue(IR_PORT,IR_PIN,DIO_u8PIN_HIGH);         // pull up

}


u8 IR_u8SensorDetectsLine(void)
{
	u8  Local_u8Value ;

	DIO_u8ReadPinValue(IR_PORT,IR_PIN,&Local_u8Value);

	return Local_u8Value;

}

void IR_voidMechanism(void)
{
	u8 Local_u8IR_Read ;
	Local_u8IR_Read = IR_u8SensorDetectsLine();

	if (Local_u8IR_Read == WHITE)
	{
		MotorDriver_voidStop();
	}
	else if (Local_u8IR_Read == BLACK)
	{
		MD_u8PreDuty=100;
		MotorDriver_voidMoveForward();
	}
}

