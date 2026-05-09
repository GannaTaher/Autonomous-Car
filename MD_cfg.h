/*
 * MD_cfg.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef MOTORDRIVER_MD_CFG_H_
#define MOTORDRIVER_MD_CFG_H_


/*
 * This header file contains the interface for DIO operations.
 */
#include "../DIO/DIO_interface.h"

/*
 * This macro defines the DIO port to which the motor driver is connected.
 */
#define MD_PORT  DIO_u8PORTC

/*
 * This macro defines the DIO pin for IN1 of the motor driver.
 */
#define MD_INT1   DIO_u8PIN1

/*
 * This macro defines the DIO pin for IN2 of the motor driver.
 */
#define MD_INT2   DIO_u8PIN2

/*
 * This macro defines the DIO pin for IN3 of the motor driver.
 */
#define MD_INT3   DIO_u8PIN3

/*
 * This macro defines the DIO pin for IN4 of the motor driver.
 */
#define MD_INT4   DIO_u8PIN4

#endif /* MOTORDRIVER_MD_CFG_H_ */
