/*
 * main.c
 *
 *  Created on: 2 lis 2018
 *      Author: Mike
 */

#include "Functions/LCD_HD44780/HD44780.h"
#include "L3GD20H.h"

char* IntToString(uint8_t data)
{


	return 0;
}

int main(void)
{
	LCD_SwitchOn();
	char test;
    GYRO_WriteByte(0b00100000,0b00001111);

	while(1)
	{

		test = GYRO_ReadByte(OUT_Y_L);
		LCD_SetChar(1,1,test);
		_delay_ms(300);
		LCD_Clear();

	}
	return 0;
}
