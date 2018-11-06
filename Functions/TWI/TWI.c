/*
 * TWI.c
 *
 *  Created on: 3 lis 2018
 *      Author: Mike
 */

#include "TWI.h"

// procedura transmisji sygna³u START
void TWI_Start(void)
{
TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while (!(TWCR & (1<<TWINT)));
}

// procedura transmisji sygna³u STOP
void TWI_Stop(void)
{
TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
while ((TWCR & (1<<TWSTO)));
}

// procedura transmisji bajtu danych
void TWI_Write(uint8_t data)
{
TWDR = data;
TWCR = (1<<TWINT) | (1<<TWEN);
while (!(TWCR & (1<<TWINT)));
}

//procedura odczytu bajtu danych
uint8_t TWI_Read(uint8_t ack)
{
TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
while (!(TWCR & (1<<TWINT)));
return TWDR;
}

