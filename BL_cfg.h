/*
 * BL_Cfg.h
 *
 *  Created on: Aug 5, 2025
 *      Author: lenovo
 */

#ifndef GRADUATION_CFG_H_
#define GRADUATION_CFG_H_

/*
 * Connection with Bluetooth through USART
 */
#define BLUETOOTH_USART	  USART1

/*Choose :
	1- USART_POLLING_DISABLE       // Polling mechanism disabled
	2- USART_POLLING_ENABLE       // Polling mechanism enabled
*/


#define BLUETOOTH_USART_POLLING  USART_POLLING_DISABLE

#endif /* GRADUATION_CFG_H_ */
