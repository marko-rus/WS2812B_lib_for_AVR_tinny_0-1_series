/*
 * Пример работы со светодиодной лентой WS2812B
 */ 

#define F_CPU 20000000
#define ledCount 8 // количество светодиодов
#include <avr/io.h>
#include <util/delay.h>
#include "WS2812B.h"


int main(void)
{
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0x00); // Отключение делителя честоты
	WsInit; // Инициализация пина для работы с лентой
	
	int i;
	while(1) // Лента мигает зеленым цветом
	{
		for (i = 0; i < ledCount; i++) WsSendPixel(0, 255, 0);
		_delay_ms(1000);
		WsClear(ledCount);
		_delay_ms(1000);
	}
	
}

