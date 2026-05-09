/*
 * UART_prog.c
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/ERR_TYPE.h"


#include "UART_interface.h"
#include "UART_reg.h"
#include "UART_prv.h"
#include "UART_cfg.h"

u8  Global_u8TXData  ;
u8 *Global_pu8RXData ;


void UART_voidInit(void)
{
	u8 Local_u8UCSRCValue = 0b10000000;

	u16 Local_u16BaudRate = 51 ;
	UBRRL = (u8)Local_u16BaudRate ;
	UBRRH = (u8)(Local_u16BaudRate >> 8);

	/*normal Speed*/
	CLR_BIT(UCSRA,UCSRA_U2X);

	/* Data Size --> b bit*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);


	/* Enable Asyncronus */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);

	/* no parity bit */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);

	/* Enable 2 stop bit */
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);


	/* update UCSRC */
	UCSRC = Local_u8UCSRCValue ;

	/* Enable TX ,RX*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

}

void UART_voidSendData(u8 Copy_u8Data)
{
	/* wait until the  UDR empty */
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);

	/* Send Data */
	UDR = Copy_u8Data ;

	while(GET_BIT(UCSRA,UCSRA_TXC) == 0);
}

u8 UART_u8ReveiveData(u8 *Copy_pu8Data)
{
	u8 Local_u8ErrorSate = OK ;
	u8 Local_u8TimeOut = 0;

	if(Copy_pu8Data != NULL)
	{
		/* wait until the receive register is complete  */
		while((GET_BIT(UCSRA,UCSRA_RXC) == 0) && Local_u8TimeOut < UART_TIMEOUT){
			Local_u8TimeOut++;
		}
		if(Local_u8TimeOut == UART_TIMEOUT){
			Local_u8ErrorSate = NOK;
			return -1;
		}
		else
		{
			*Copy_pu8Data = UDR ;
			Local_u8TimeOut = 0;
		}
	}
	else
	{
		Local_u8ErrorSate = NULL_POINTER ;
	}

	return Local_u8ErrorSate ;
}


u8 UART_u8AsynReveiveData(u8 *Copy_pu8Data)
{
	u8 Local_u8ErrorSate = OK ;

	if(Copy_pu8Data != NULL)
	{
		/* Enable RX Complete interrupt */
		SET_BIT(UCSRB,UCSRB_RXCIE);

		Global_pu8RXData = Copy_pu8Data ;
	}
	else
	{
		Local_u8ErrorSate = NULL_POINTER ;
	}

	return Local_u8ErrorSate ;
}

void UART_voidAsyncSendData(u8 Copy_u8Data)
{
	/* enable UDAR Data Register Empty */
	SET_BIT(UCSRB,UCSRB_UDRIE);

	Global_u8TXData = Copy_u8Data ;
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	*Global_pu8RXData = UDR;
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	UDR = Global_u8TXData;
}

