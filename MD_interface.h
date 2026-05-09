/*
 * MD_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef MOTORDRIVER_MD_INTERFACE_H_
#define MOTORDRIVER_MD_INTERFACE_H_

/*
 * This function initializes the motor driver.
 *     by make Direction of 4Pins is Output
 *     , call Timer0 & Timer2 for each two pins
 *       to Configure PWM channels for speed control in Compare match with MAX_SPEED (255)
 */
void MotorDriver_voidInit(void);


/*
 * This function controls the speed of both motors connected to the motor driver.
 * Copy_u8DutyCycle The duty cycle value for controlling the speed (0-255).
 */
void MotorDriver_voidControlSpeed(u8 Copy_DutyCycle);


/*
 * This function moves the motors forward.
 *     by make Pin1 & Pin3 High and Pin2 & Pin4 Low as this make Car move Forward
 *     and control Speed by MotorDriver_voidControlSpeed and display it in LCD
 */
void MotorDriver_voidMoveForward(void);


/*
 * This function moves the motors backward.
 *     by make Pin1 & Pin3 Low and Pin2 & Pin4 High as this make Car move Backward
 *     and control Speed by MotorDriver_voidControlSpeed and display it in LCD
 */
void MotorDriver_voidMoveBackward(void);


/*
 * This function turns the motors right.
 *     by make Pin2 High and other Pins are Low as this make Car move Right
 *     and control Speed by MotorDriver_voidControlSpeed and display it in LCD
 */
void MotorDriver_voidMoveRight(void);


/*
 * This function turns the motors left.
 * by make Pin4 High and other Pins are Low as this make Car move Left
 *     and control Speed by MotorDriver_voidControlSpeed and display it in LCD
 */
void MotorDriver_voidMoveLeft(void);

/*
 * This function stops the motors.
 *     by make all Pins Low
 */
void MotorDriver_voidStop(void);

#endif /* MOTORDRIVER_MD_INTERFACE_H_ */
