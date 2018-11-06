/*
 * L3GD20H.c
 *
 *  Created on: 3 lis 2018
 *      Author: Mike
 */

#include "L3GD20H.h"

uint8_t GYRO_ReadByte(uint8_t adress)
{
	uint8_t data;
	TWI_Start();
	TWI_Write(SAB_W);
	TWI_Write(adress);
	TWI_Start();
	TWI_Write(SAB_R);
	data = TWI_Read(0);
	TWI_Stop();
	return data;
}

void GYRO_WriteByte(uint8_t adress, uint8_t data)
{
	TWI_Start();
	TWI_Write(SAB_W);
	TWI_Write(adress);
	TWI_Write(data);
	TWI_Stop();
	_delay_ms(15);

}
