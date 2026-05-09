/*
 * BL_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef GRADUATION_INTERFACE_H_
#define GRADUATION_INTERFACE_H_

// Initialize the Bluetooth
void Bluetooth_Init(void);


/* Receive Data from Bluetooth Asynchronization (Interrput)
 *    by path a Parameter to UART_u8AsynReveiveData function take by pointer the point to data sent
 */
u8 Bluetooth_AsynReceiveData(void);


/* Receive Data from Bluetooth Synchronization (Pooling)
 *    by path a Parameter to UART_u8ReveiveData function take by pointer the point to data sent
 */
 u8 Bluetooth_ReceiveData(void);


#endif /* GRADUATION_INTERFACE_H_ */
