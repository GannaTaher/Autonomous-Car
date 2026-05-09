/*
 * IR_interface.h
 *
 *  Created on: ???/???/????
 *      Author: GANNA TAHER
 */

#ifndef IR_IR_INTERFACE_H_
#define IR_IR_INTERFACE_H_

/* Initialize IR Sensor
 *    PD3 is the Receiver that take the Reflected InfraRed Rays
 *    Its value is High (Pull up)
 */
void IR_voidInit(void);


// A Function that read the Value of the PD3 and Return it
u8 IR_u8SensorDetectsLine(void);


/* A Function that explain its Mechanism
 *      if the value read is WHITE (0) this mean Car Stop
 *      ,  the value read is BLACK (1) this mean Car still walk --> Follow the line
 */
void IR_voidMechanism(void);

#endif /* IR_IR_INTERFACE_H_ */
