/*
 * main.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERR_TYPE.h"
#include <util/delay.h>

#include "DIO/DIO_interface.h"
#include "UART/UART_interface.h"
#include "GIE/GIE_Interface.h"
#include "CLCD/CLCD_interface.h"
#include "BLUETOOTH/BL_interface.h"

#include "MotorDriver/MD_interface.h"
#include "IR/IR_interface.h"


u8  MD_u8PreDuty = 100 ;

void RC_Desicion(u8 HC5_u8Input);


void RC_Desicion(u8 HC5_u8Input)
{
	switch (HC5_u8Input)
	{
	case 'F':
		MotorDriver_voidMoveForward();
		break;

	case 'B':
		MotorDriver_voidMoveBackward();
		break;

	case 'L':
		MotorDriver_voidMoveLeft();
		break;

	case 'R':
		MotorDriver_voidMoveRight();
		break;

	case 'S':
		MotorDriver_voidStop();
		break;

	case '1':
		MotorDriver_voidControlSpeed(50);
		MD_u8PreDuty =50;
		break;

	case '2':
		MotorDriver_voidControlSpeed(60);
		MD_u8PreDuty =60;
		break;

	case '3':
		MotorDriver_voidControlSpeed(65);
		MD_u8PreDuty =65;
		break;

	case '4':
		MotorDriver_voidControlSpeed(70);
		MD_u8PreDuty =70;
		break;

	case '5':
		MotorDriver_voidControlSpeed(75);
		MD_u8PreDuty =75;
		break;

	case '6':
		MotorDriver_voidControlSpeed(80);
		MD_u8PreDuty =80;
		break;

	case '7':
		MotorDriver_voidControlSpeed(85);
		MD_u8PreDuty =85;
		break;

	case '8':
		MotorDriver_voidControlSpeed(90);
		MD_u8PreDuty =90;
		break;

	case '9':
		MotorDriver_voidControlSpeed(95);
		MD_u8PreDuty =95;
		break;

	case 'q':
		MotorDriver_voidControlSpeed(100);
		MD_u8PreDuty =100;
		break;

	default:
		MotorDriver_voidStop();
		break;
	}
}

#endif /* MAIN_H_ */
