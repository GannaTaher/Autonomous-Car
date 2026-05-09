/*
 * BL_Prog.c
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/ERR_TYPE.h"


#include "../UART/UART_interface.h"

#include "BL_interface.h"
#include "BL_prv.h"
#include "BL_cfg.h"

void Bluetooth_Init(void)
{
	UART_voidInit();
}

u8 Bluetooth_AsynReceiveData(void)
{
	u8 Local_u8RecievedData;

	UART_u8AsynReveiveData(&Local_u8RecievedData);

	return Local_u8RecievedData ;

}


u8 Bluetooth_ReceiveData(void)
{
	u8 Local_u8RecievedData;

	UART_u8ReveiveData(&Local_u8RecievedData);

	return Local_u8RecievedData ;

}
