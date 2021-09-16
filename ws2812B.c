/*
 * WS2812B.c
 *
 * Created: 8.7.2021 г. 21:47:34
 * Author: Марк Бомштейн
 */ 

#include "WS2812B.h"

void Set0() // Отправляется ноль, задержка ~0.4 мкс
{
	SetOutBit;
	asm("nop");asm("nop");asm("nop");asm("nop"); // задержка 0,4 мкс
	ClearOutBit;
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop"); // задержка 0,8 мкс
}

void Set1() // Отправляеться еденица, задержка ~0.8 мкс
{
	SetOutBit;
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop"); // задержка 0,8 мкс
	ClearOutBit;
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop"); // задержка 0,8 мкс
}

void WsSendByte(int hex) // Функция для отправки одного байта данных на ленту. Использует маску для работы
{
	int mask = 0b10000000;
	
	for (int n = 0; n < 8; n++)
	{
		if ((hex & mask) == mask) Set1();
		else Set0();
		mask = mask >> 1;
	}
}

void WsSendPixel(int R, int G, int B) // Функция для вывода 1 пикселя на ленту в формате GRB. Для изменения формата надо поменять буквы G R B местами
{
	WsSendByte(G);
	WsSendByte(R);
	WsSendByte(B);
}

void WsClear(int a) // Просто функция для очистки a количества пикселей
{
	for (int i = 0; i < a; i++) WsSendPixel(0,0,0);
}