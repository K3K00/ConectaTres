/*
 * Animaciones.c
 *
 *  Created on: 24 jun 2026
 *      Author: Administrador
 */
#include "Animaciones.h"
#include "main.h"
#include "ws2812b.h"

void Inicio(void) {
	WS2812_LED_N_Color(1, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(3, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(4, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(6, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(7, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(8, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(10, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(11, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(12, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(15, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(20, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(23, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(24, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(27, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(29, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(50);
	WS2812_LED_N_Color(30, 0, 0, 100);
	WS2812_Manda_Trama();
	HAL_Delay(2000);

	WS2812_LED_N_Color(1, 0, 0, 0);
	WS2812_LED_N_Color(3, 0, 0, 0);
	WS2812_LED_N_Color(4, 0, 0, 0);
	WS2812_LED_N_Color(6, 0, 0, 0);
	WS2812_LED_N_Color(7, 0, 0, 0);
	WS2812_LED_N_Color(8, 0, 0, 0);
	WS2812_LED_N_Color(10, 0, 0, 0);
	WS2812_LED_N_Color(11, 0, 0, 0);
	WS2812_LED_N_Color(12, 0, 0, 0);
	WS2812_LED_N_Color(15, 0, 0, 0);
	WS2812_LED_N_Color(20, 0, 0, 0);
	WS2812_LED_N_Color(23, 0, 0, 0);
	WS2812_LED_N_Color(24, 0, 0, 0);
	WS2812_LED_N_Color(27, 0, 0, 0);
	WS2812_LED_N_Color(29, 0, 0, 0);
	WS2812_LED_N_Color(30, 0, 0, 0);
	WS2812_Manda_Trama();
}

void jvj(void) {
	WS2812_LED_N_Color(0, 0, 10, 0);
	WS2812_LED_N_Color(4, 0, 10, 0);
	WS2812_LED_N_Color(5, 0, 10, 0);
	WS2812_LED_N_Color(6, 0, 10, 0);
	WS2812_LED_N_Color(7, 0, 10, 0);
	WS2812_LED_N_Color(8, 0, 10, 0);
	WS2812_LED_N_Color(10, 0, 10, 0);
	WS2812_LED_N_Color(20, 0, 10, 0);
	WS2812_LED_N_Color(24, 0, 10, 0);
	WS2812_LED_N_Color(25, 0, 10, 0);
	WS2812_LED_N_Color(26, 0, 10, 0);
	WS2812_LED_N_Color(27, 0, 10, 0);
	WS2812_LED_N_Color(28, 0, 10, 0);
	WS2812_LED_N_Color(30, 0, 10, 0);
	WS2812_Manda_Trama();
}

void jvcpu() {
	WS2812_LED_N_Color(0, 0, 10, 0);
	WS2812_LED_N_Color(2, 0, 10, 0);
	WS2812_LED_N_Color(5, 0, 10, 0);
	WS2812_LED_N_Color(6, 10, 0, 0);
	WS2812_LED_N_Color(7, 0, 10, 0);
	WS2812_LED_N_Color(9, 0, 10, 0);
	WS2812_LED_N_Color(10, 10, 0, 0);
	WS2812_LED_N_Color(11, 0, 10, 0);
	WS2812_LED_N_Color(12, 0, 10, 0);
	WS2812_LED_N_Color(14, 0, 10, 0);
	WS2812_LED_N_Color(20, 0, 10, 0);
	WS2812_LED_N_Color(24, 0, 10, 0);
	WS2812_LED_N_Color(25, 0, 10, 0);
	WS2812_LED_N_Color(26, 0, 10, 0);
	WS2812_LED_N_Color(27, 0, 10, 0);
	WS2812_LED_N_Color(28, 0, 10, 0);
	WS2812_LED_N_Color(30, 0, 10, 0);
	WS2812_Manda_Trama();
}

void ganaazul(void) {
	WS2812_LED_N_Color(31, 0, 0, 50);  //Azul
	WS2812_LED_N_Color(28, 0, 0, 50);
	WS2812_LED_N_Color(19, 0, 0, 50);
	WS2812_LED_N_Color(16, 0, 0, 50);
	WS2812_LED_N_Color(15, 0, 0, 50);
	WS2812_LED_N_Color(14, 0, 0, 50);
	WS2812_LED_N_Color(13, 0, 0, 50);
	WS2812_LED_N_Color(3, 0, 0, 50);
	WS2812_LED_N_Color(2, 0, 0, 50);
	WS2812_LED_N_Color(1, 0, 0, 50);

	WS2812_LED_N_Color(30, 50, 40, 0);  //Amarillo
	WS2812_LED_N_Color(29, 50, 40, 0);
	WS2812_LED_N_Color(27, 50, 40, 0);
	WS2812_LED_N_Color(26, 50, 40, 0);
	WS2812_LED_N_Color(25, 50, 40, 0);
	WS2812_LED_N_Color(24, 50, 40, 0);
	WS2812_LED_N_Color(23, 50, 40, 0);
	WS2812_LED_N_Color(22, 50, 40, 0);
	WS2812_LED_N_Color(21, 50, 40, 0);
	WS2812_LED_N_Color(20, 50, 40, 0);
	WS2812_LED_N_Color(18, 50, 40, 0);
	WS2812_LED_N_Color(17, 50, 40, 0);
	WS2812_LED_N_Color(12, 50, 40, 0);
	WS2812_LED_N_Color(11, 50, 40, 0);
	WS2812_LED_N_Color(9, 50, 40, 0);
	WS2812_LED_N_Color(8, 50, 40, 0);
	WS2812_LED_N_Color(7, 50, 40, 0);
	WS2812_LED_N_Color(5, 50, 40, 0);
	WS2812_LED_N_Color(4, 50, 40, 0);
	WS2812_LED_N_Color(0, 50, 40, 0);

	WS2812_LED_N_Color(10, 0, 50, 0);  //Verde
	WS2812_LED_N_Color(6, 0, 50, 0);
	WS2812_Manda_Trama();
}

void ganarojo(void) {
	WS2812_LED_N_Color(31, 50, 0, 0);
	WS2812_LED_N_Color(28, 50, 0, 0);
	WS2812_LED_N_Color(19, 50, 0, 0);
	WS2812_LED_N_Color(16, 50, 0, 0);
	WS2812_LED_N_Color(15, 50, 0, 0);
	WS2812_LED_N_Color(14, 50, 0, 0);
	WS2812_LED_N_Color(13, 50, 0, 0);
	WS2812_LED_N_Color(3, 50, 0, 0);
	WS2812_LED_N_Color(2, 50, 0, 0);
	WS2812_LED_N_Color(1, 50, 0, 0);

	WS2812_LED_N_Color(30, 50, 40, 0);  //Amarillo
	WS2812_LED_N_Color(29, 50, 40, 0);
	WS2812_LED_N_Color(27, 50, 40, 0);
	WS2812_LED_N_Color(26, 50, 40, 0);
	WS2812_LED_N_Color(25, 50, 40, 0);
	WS2812_LED_N_Color(24, 50, 40, 0);
	WS2812_LED_N_Color(23, 50, 40, 0);
	WS2812_LED_N_Color(22, 50, 40, 0);
	WS2812_LED_N_Color(21, 50, 40, 0);
	WS2812_LED_N_Color(20, 50, 40, 0);
	WS2812_LED_N_Color(18, 50, 40, 0);
	WS2812_LED_N_Color(17, 50, 40, 0);
	WS2812_LED_N_Color(12, 50, 40, 0);
	WS2812_LED_N_Color(11, 50, 40, 0);
	WS2812_LED_N_Color(9, 50, 40, 0);
	WS2812_LED_N_Color(8, 50, 40, 0);
	WS2812_LED_N_Color(7, 50, 40, 0);
	WS2812_LED_N_Color(5, 50, 40, 0);
	WS2812_LED_N_Color(4, 50, 40, 0);
	WS2812_LED_N_Color(0, 50, 40, 0);

	WS2812_LED_N_Color(10, 0, 50, 0);
	WS2812_LED_N_Color(6, 0, 50, 0);
	WS2812_Manda_Trama();
}

void ganacpu(void) {
	WS2812_LED_N_Color(31, 0, 0, 0);
	WS2812_LED_N_Color(28, 0, 0, 0);
	WS2812_LED_N_Color(19, 0, 0, 0);
	WS2812_LED_N_Color(16, 0, 0, 0);
	WS2812_LED_N_Color(15, 0, 0, 0);
	WS2812_LED_N_Color(14, 0, 0, 0);
	WS2812_LED_N_Color(13, 0, 0, 0);
	WS2812_LED_N_Color(3, 0, 0, 0);
	WS2812_LED_N_Color(2, 0, 0, 0);
	WS2812_LED_N_Color(1, 0, 0, 0);

	WS2812_LED_N_Color(30, 50, 40, 0);  //Amarillo
	WS2812_LED_N_Color(29, 50, 40, 0);
	WS2812_LED_N_Color(27, 50, 40, 0);
	WS2812_LED_N_Color(26, 50, 40, 0);
	WS2812_LED_N_Color(25, 50, 40, 0);
	WS2812_LED_N_Color(24, 50, 40, 0);
	WS2812_LED_N_Color(23, 50, 40, 0);
	WS2812_LED_N_Color(22, 50, 40, 0);
	WS2812_LED_N_Color(21, 50, 40, 0);
	WS2812_LED_N_Color(20, 50, 40, 0);
	WS2812_LED_N_Color(18, 50, 40, 0);
	WS2812_LED_N_Color(17, 50, 40, 0);
	WS2812_LED_N_Color(12, 50, 40, 0);
	WS2812_LED_N_Color(11, 50, 40, 0);
	WS2812_LED_N_Color(9, 50, 40, 0);
	WS2812_LED_N_Color(8, 50, 40, 0);
	WS2812_LED_N_Color(7, 50, 40, 0);
	WS2812_LED_N_Color(5, 50, 40, 0);
	WS2812_LED_N_Color(4, 50, 40, 0);
	WS2812_LED_N_Color(0, 50, 40, 0);

	WS2812_LED_N_Color(10, 0, 50, 0);
	WS2812_LED_N_Color(6, 0, 50, 0);
	WS2812_Manda_Trama();
}

void empate (void){
    WS2812_LED_N_Color(2, 50, 50, 50);
    WS2812_LED_N_Color(4, 50, 50, 50);
    WS2812_LED_N_Color(5, 50, 50, 50);
    WS2812_LED_N_Color(6, 50, 50, 50);
    WS2812_LED_N_Color(7, 50, 50, 50);
    WS2812_LED_N_Color(8, 50, 50, 50);
    WS2812_LED_N_Color(9, 50, 50, 50);
    WS2812_LED_N_Color(10, 50, 50, 50);
    WS2812_LED_N_Color(11, 50, 50, 50);
    WS2812_LED_N_Color(13, 50, 50, 50);
    WS2812_LED_N_Color(20, 50, 50, 50);
    WS2812_LED_N_Color(21, 50, 50, 50);
    WS2812_LED_N_Color(22, 50, 50, 50);
    WS2812_LED_N_Color(23, 50, 50, 50);
    WS2812_LED_N_Color(26, 50, 50, 50);
    WS2812_LED_N_Color(27, 50, 50, 50);
}
