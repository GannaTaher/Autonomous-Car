/*
 * TIMER_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_FALLING_EDGE	1
#define ICU_RISING_EDGE		2

void TIMER0_voidInit(void);
void TIMER1_voidInit(void);
void TIMER2_voidInit(void);


void TIMER1_voidSetICR(u16 Copy_u16Top);

void TIMER0_voidSetPreload(u8 Copy_u8Value);
void TIMER0_voidSetCompMatch(u8 Copy_u8Value);
void TIMER1_voidSetCompMatch(u16 Copy_u16Value);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

void TIMER2_voidSetPreload(u8 Copy_u8Value);
void TIMER2_voidSetCompMatch(u8 Copy_u8Value);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBack)(void));

void Timer_PWM_Start(u8 Copy_u8DutyCycle);

void ICU_voidInit(void);
void ICU_voidSetEdge(u8 Copy_u8Sense);
void ICU_voidEnable(void);
void ICU_voidDisable(void);

u8 ICU_u8SetCallBack(void (*Copy_pvCallBack)(void));
u16 ICU_u16GetReading(void);



#endif /* TIMER_INTERFACE_H_ */
