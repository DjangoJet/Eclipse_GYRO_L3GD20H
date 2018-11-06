/*
 * TWI.h
 *
 *  Created on: 3 lis 2018
 *      Author: Mike
 */

#ifndef TWI_H_
#define TWI_H_

#include <avr/io.h>

// procedura transmisji sygna³u START
void TWI_Start(void);
// procedura transmisji sygna³u STOP
void TWI_Stop(void);
// procedura transmisji bajtu danych
void TWI_Write(uint8_t data);
//procedura odczytu bajtu danych
uint8_t TWI_Read(uint8_t ack);

#endif /* TWI_H_ */
