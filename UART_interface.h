/*
 * UART_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit(void);

void UART_voidSendData(u8 Copy_u8Data);

u8 UART_u8ReveiveData(u8 *Copy_pu8Data);

void UART_voidAsyncSendData(u8 Copy_u8Data);
u8 UART_u8AsynReveiveData(u8 *Copy_pu8Data);


#endif /* UART_INTERFACE_H_ */
