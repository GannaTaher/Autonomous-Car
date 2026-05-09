/*
 * Ultra_Prog.c
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERR_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../DIO/DIO_interface.h"
#include "../TIMER/TIMER_interface.h"
#include "../GIE/GIE_Interface.h"
#include "../MotorDriver/MD_interface.h"
#include "../BLUETOOTH/BL_interface.h"

#include "Ultra_Cfg.h"
#include "Ultra_Prv.h"
#include "Ultra_interface.h"



u16 ULT_u16EchoTime ;
u8  ULT_u8Counter = 0;


void Ultra_voidInit(void)
{
	DIO_u8SetPinDirection(ULTRA_PORT,ULTRA_TRIG,DIO_u8PIN_OUTPUT);   // Transmitter
	DIO_u8SetPinDirection(ULTRA_PORT,ULTRA_ECHO,DIO_u8PIN_INPUT);   // Receiver


	ICU_voidInit();
	ICU_u8SetCallBack(Ultra_voidEdgeProc);
	TIMER1_voidInit();
	GIE_VoidEnable();
}

void Ultra_voidTrigger(void)
{

	DIO_u8SetPinValue(ULTRA_PORT,ULTRA_TRIG,DIO_u8PIN_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(ULTRA_PORT,ULTRA_TRIG,DIO_u8PIN_LOW);

}


f32 Ultra_f32ReadDistance(void){

	f32 Local_u8Distance;
	Ultra_voidTrigger();

	Local_u8Distance = ULT_u16EchoTime /58.8 ;
	return Local_u8Distance;

}

// ICU interrupt function
void Ultra_voidEdgeProc(void){
	ULT_u8Counter++;

	if (ULT_u8Counter == 1 )
	{
		TIMER1_voidSetTimerValue(0);
		ICU_voidSetEdge(ICU_FALLING_EDGE);
	}
	else if(ULT_u8Counter ==2)
	{
		ULT_u16EchoTime = ICU_u16GetReading();
		ICU_voidSetEdge(ICU_RISING_EDGE);
		ULT_u8Counter = 0;
	}

}

