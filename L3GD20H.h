/*
 * registers.h
 *
 *  Created on: 2 lis 2018
 *      Author: Mike
 */

#ifndef L3GD20H_H_
#define L3GD20H_H_

#include <avr/io.h>
#include <util/delay.h>

#include "Functions/TWI/TWI.h"


/* Adres jedno bijtowy (8 bit) urz¹dzenia L3GD20H. Jest on wysy³any po sygnale ST.
 * Pierwsze 7 bitów zawiera adres urz¹dzenia (1101011b) ostatni mówi o tym czy
 * Master czyta z Slave czy pisze do niego
 */
#define SAB_W 0b11010110 // wpisuje do urz¹dzenia
#define SAB_R 0b11010111 // odbiera z urz¹dzenia

/* Sub-adresy rejestru w Slave + pierwszy bit oznaczaj¹cy automatyczny przyrost
 * adresu co odebrany/wys³any bajt (ustawione 1)
 */
#define OUT_X_L 0b00101000
#define OUT_X_H 0b00101001
#define OUT_Y_L 0b00101010
#define OUT_Y_H 0b00101011
#define OUT_Z_L 0b00101100
#define OUT_Z_H 0b00101101

#define AUTO_UP 0b10000000


//Funkcje do obs³ugi TWI
uint8_t GYRO_ReadByte(uint8_t adress);
void GYRO_WriteByte(uint8_t adress, uint8_t data);

#endif /* L3GD20H_H_ */
