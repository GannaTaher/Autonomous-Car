/*
 * Ultra_Cfg.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef ULTRASONIC_ULTRA_CFG_H_
#define ULTRASONIC_ULTRA_CFG_H_

// Header file interface of DIO that have all Ports & Pins to be connected
#include "../DIO/DIO_interface.h"


// The PortD in MicroProcessor is the port which the Ultrasonic is connected
#define  ULTRA_PORT         DIO_u8PORTD


// PD5 in MicroProcessor is the pin which the Trigger is connected
#define  ULTRA_TRIG         DIO_u8PIN5


// PD6 in MicroProcessor is the pin which the Echo is connected
#define  ULTRA_ECHO         DIO_u8PIN6

#endif /* ULTRASONIC_ULTRA_CFG_H_ */


