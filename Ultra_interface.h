/*
 * Ultra_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef ULTRASONIC_ULTRA_INTERFACE_H_
#define ULTRASONIC_ULTRA_INTERFACE_H_

/*
 * Initialize Ultrasonic Sensor
 *    by set its 2 Pins --> Trigger (Transmitter --> output) & Echo (Receiver --> input)
 *    initiate ICU ,Timer1 , enable  Global Interput Enable (GIE)
 */
void Ultra_voidInit(void);

/*
 * make Trigger(transmitter) High means send signal each 10us
 */
void Ultra_voidTrigger(void);

/*
 * Function to measure Distance
 */
f32 Ultra_f32ReadDistance(void);

/*
 * increase global counter to start to send signal and wait until reach to end (falling_edge)
 *       second get reading from ICU_u16GetReading() and get to Rising
 *       return global counter to Zero when start again
 */
void Ultra_voidEdgeProc(void);


#endif /* ULTRASONIC_ULTRA_INTERFACE_H_ */
