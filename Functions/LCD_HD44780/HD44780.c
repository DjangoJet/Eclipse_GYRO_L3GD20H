/*
 * HD44780.c
 *
 *  Created on: 3 lis 2018
 *      Author: Mike
 */

#include "HD44780.h"

void LCD_SendChar(int8_t data)
{
	// wlaczenie linii ENABLE
	PortLED |= (1<<EN);

	//wys�anie 4 starszych bit�w
	PortLED = (data & 0xf0)|(PortLED & 0x0f);

	// potwierdzenie wys�ana danych poprzez opadni�cie ENABLE
	PortLED &= ~(1<<EN);

	// odczekanie jednego cyklu
	asm volatile("nop");

	PortLED |= (1<<EN);
	//wys�anie 4 m�odszych bit�w
	PortLED = ((data & 0x0f)<<4)|(PortLED & 0x0f);
	PortLED &= ~(1<<EN);

	// odczekanie niezb�dnej d�ugo�ci czasu na potwierdzenie wprowadzenia danych
	_delay_us(40);
}

void LCD_Clear()
{
	// przestawia na linii RS warto�� na 0 po to by wys�a� komend� a nie dane
	PortLED &= ~(1<<RS);
	// wysy�amy polecenie wyczyszczenia LCD
	LCD_SendChar(1);

	// przestawia lini� RS na warto�� 1 odpowiadaj�c� wprowadzaniu danych
	PortLED |= (1<<RS);

	// maksymalny czas oczekiwania na wyczyszczenie ekranu LCD
	_delay_ms(1.64);
}

void LCD_SwitchOn()
{
	// ustawienie kierunku wyj�ciowego dla wszystkich linii
	LCD_DDR = (0xf0)|(_BV(RS))|(_BV(EN));

	// ustawienie pocz�tkowego stanu niskiego na wszystkich liniach
	PortLED = 0;


	// rozpocz�cie wysy�ania komendy
	PortLED &= ~(1<<RS);
	// ustawienie parametr�w wy�wietlacza
	// BIT 4: 1 - 8 linii, 0 - 4 linie,
	// BIT 3: 1 - 2 wiersze, 0 - 1 wiersz
	// BIT 2: 0 - wymiar znaku 5x8; 1 - wymiar 5x10
	LCD_SendChar(0b00101000);
	PortLED |= (1<<RS);

	PortLED &= ~(1<<RS);
	// BIT 2 - tryb pracy wy�wietlacza (inkrementowanie zapisu danych)
	// BIT1: 1 - przesuni�cie okna, 0 - przesuni�cie kursora
	LCD_SendChar(0b00000110);
	PortLED |= (1<<RS);


	PortLED &= ~(1<<RS);
	// BIT2: 1 - wy�wietlacz w��czony, 0 - wy��czony
	// BIT1: 1 - w��czenie wy�wietlania kursora, 0 - kursor niewidoczny
	// BIT0: 1 - kursor miga, 0 - kursor nie miga
	LCD_SendChar(0b00001100);
	PortLED |= (1<<RS);

	LCD_Clear();
}

void LCD_SetChar(int8_t row, int8_t col, char letter)
{

	int Position = 0;
	int i;
	if(row > 1)
	{
		Position += 40;
	}

	Position += col-1;

	for(i=0;i<Position;i++)
	{
		PortLED &= ~(1<<RS);
		LCD_SendChar(0b00010100);
		PortLED |= (1<<RS);
	}

    LCD_SendChar(letter);

	for(i=0;i<Position+1;i++)
	{
		PortLED &= ~(1<<RS);
		LCD_SendChar(0b00010000);
		PortLED |= (1<<RS);
	}
}

void LCD_SetString(int8_t row, int8_t col, char *text)
{
    int i = 0;

    for(i=0; !(text[i]=='\0'); i++)
    {
    	LCD_SetChar(row, col+i, text[i]);
    	_delay_ms(700);
    }

}

