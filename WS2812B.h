/*
 * WS2812B.h
 *
 * Created: 8.7.2021 г. 21:46:56
 * Author: Марк Бомштейн
 * Простая и легкая библиотека для управления адресной светодиодной лентой WS2812B
 * Для работы необходим контроллер AVR серии tiny-0 или tiny-1 (attiny202, attiny212, attiny404, attiny414 и пр.) и работающий  на частоте 20 МГц
 */ 


#ifndef WS2812B_H_
#define WS2812B_H_

#include <avr/io.h>

#define mPin 7 // Пин для подключения ленты
#define  mMask (1<<mPin)
#define mPort PORTA // Порт для подключения ленты
#define WsInit mPort.PIN7CTRL = 0b00001000; // PINxCTRL; x = mPin

#define ClearOutBit    mPort.OUTCLR |= (1<<mPin)  //0 на выход
#define SetOutBit      mPort.OUTSET |= (1<<mPin)     //1 на выход

void WsSendByte(int hex); // Отправка байта на ленту
void WsSendPixel(int R, int G, int B); // Отправка 1 пикселя на ленту в формате GRB. Если нужно переделать на другой формат см. WS2812B.c
void WsClear(int a); // Очистка a пикселей

#endif /* WS2812B_H_ */