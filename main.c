/*
 * main.c
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#include "main.h"
#include "Ultrasonic/Ultra_interface.h"


void main (void)
{
	volatile  f32 Local_f32Distance;
	extern  u8  MD_u8PreDuty ;

	//IR
	DIO_u8SetPortDirection(DIO_u8PORTB, DIO_u8PORT_OUTPUT);

	// MD
	DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);

	// Timer0
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);

	// Timer2
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_OUTPUT);


	Bluetooth_Init();
	MotorDriver_voidInit();
	Ultra_voidInit();
	IR_voidInit();

	while(1)
	{
		u8 BL_u8Input = Bluetooth_ReceiveData();

		if (BL_u8Input == 'K')
		{
			while(1)
			{
				IR_voidMechanism();
			}
		}
		else if ( BL_u8Input == 'P' )
		{
			while (1)
			{
				Local_f32Distance = Ultra_f32ReadDistance();

				if (Local_f32Distance < 15 )
				{
					MotorDriver_voidMoveRight();
					_delay_ms(100);
					MotorDriver_voidStop();
				}
				else
				{
					BL_u8Input = Bluetooth_ReceiveData();
					RC_Desicion(BL_u8Input);
				}
			}
		}
		else if (BL_u8Input == 'N')
		{
			while (1)
			{
				Local_f32Distance = Ultra_f32ReadDistance();

				if (Local_f32Distance < 15 )
				{
					MD_u8PreDuty=70;
					MotorDriver_voidMoveRight();
					_delay_ms(100);
					MotorDriver_voidStop();
				}
				else
				{
					MD_u8PreDuty=70;
					MotorDriver_voidMoveForward();
				}
			}
		}
	}
}






