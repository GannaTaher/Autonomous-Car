/*
 * IR_Cfg.h
 *
 *  Created on: ???/???/????
 *      Author: GANNA TAHER
 */

#ifndef IR_IR_CFG_H_
#define IR_IR_CFG_H_

// Header file interface of DIO that have all Ports & Pins to be connected
#include "../DIO/DIO_interface.h"

// The PortD in MicroProcessor is the port which the IR is connected
#define  IR_PORT        DIO_u8PORTD

// PD3 in MicroProcessor is the pin which the PIN is connected
#define  IR_PIN        DIO_u8PIN3


#endif /* IR_IR_CFG_H_ */
