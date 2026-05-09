
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/ERR_TYPE.h"


#include "TIMER_interface.h"
#include "TIMER_reg.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"

void (*TIMER0_pvCallBack)(void)	= NULL;
void (*ICU_pvCallBack)(void)	= NULL ;

void TIMER0_voidInit(void)
{
	/* Waveform Generation Mode --> fast PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	/* prescaler --> div_by 8 */
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= TIMER_PRESC ;


	/*ENABLE INTERRUPT*/
	//	SET_BIT(TIMSK,TIMSK_OCIE0);
}


void TIMER1_voidInit(void)
{
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}
void TIMER2_voidInit(void)
{
	/* Waveform Generation Mode --> fast PWM mode */
	SET_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TCCR2,TCCR2_WGM20);

	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

	/* prescaler --> div_by 8 */
	TCCR2 &= TCCR2_MASK;
	TCCR2 |= TIMER_PRESC ;

}


void TIMER0_voidSetPreload(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value ;
}


void TIMER1_voidSetICR(u16 Copy_u16Top)
{
	ICR1 = Copy_u16Top ;
}



void TIMER1_voidSetCompMatch(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value ;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value){
	TCNT1  = Copy_u16Value ;
}

void TIMER0_voidSetCompMatch(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value ;
}

void TIMER2_voidSetCompMatch(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value ;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBack)(void))
{
	u8 Local_u8ErrorState = OK ;

	if(Copy_pvCallBack != NULL)
	{
		TIMER0_pvCallBack = Copy_pvCallBack ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState;
}

void Timer_PWM_Start(u8 Local_u8DutyCycle)
{
	/* If the input duty cycle greater than 100, then set it to 100 */
	if (Local_u8DutyCycle > 100)
	{
		Local_u8DutyCycle = 100;
	}
	/* If the input duty cycle less than 0, then set it to 0 */
	if (Local_u8DutyCycle < 0)
	{
		Local_u8DutyCycle = 0;
	}
	OCR0 = (u8) ((u16) Local_u8DutyCycle * MAX_SPEED / 100);
	OCR2 = (u8) ((u16) Local_u8DutyCycle * MAX_SPEED / 100);
}


void __vector_10 (void)	__attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBack != NULL)
	{
		TIMER0_pvCallBack();
	}
}

void ICU_voidInit(void)
{

	/* rising Edge */
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	SET_BIT(TIMSK,TIMSK_TICIE1);

}
void ICU_voidSetEdge(u8 Copy_u8Sense)
{
	if(Copy_u8Sense == ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8Sense == ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
}
void ICU_voidEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);

}

u8 ICU_u8SetCallBack(void (*Copy_pvCallBack)(void))
{
	u8 Local_u8ErrorState = OK ;
	if(Copy_pvCallBack != NULL)
	{
		ICU_pvCallBack = Copy_pvCallBack ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState;
}

u16 ICU_u16GetReading(void)
{
	return 	ICR1 ;
}
void ICU_clearTimerValue(void)
{
	TCNT1 = 0;
}


void __vector_6(void) __attribute__((signal));
void __vector_6(void){

	if(ICU_pvCallBack != NULL)
	{
		ICU_pvCallBack();
	}

}
