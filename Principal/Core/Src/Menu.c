/*
 * Menu.c
 *
 *  Created on: 17 jun 2026
 *      Author: Administrador
 */

#include "Menu.h"
#include "ws2812b.h"
#include "main.h"
#include "Teclado.h"

static int tecla = 0;

int Seleccion(int modo) { //Aca quiero presentar ambas imagenes para los 2 modos.
//Realizo el barrido para ver que tecla se presiono
	int salida = 0;
	int m = 0;

	jvj();

	do {
		Barrido();
		tecla = ObtenerTecla();
		switch (tecla) {
		case (4):
			// MODO 1V1
			//Borro lo que tenga en pantalla y mando la secuencia directamente
			WS2812_RESET();
			WS2812_Manda_Trama();

			HAL_Delay(50);

			jvj();

			m = 0;
			break;
		case (16):
			// MODO 1V CPU
			WS2812_RESET();
			WS2812_Manda_Trama();

			HAL_Delay(50);

			jvcpu();

			m = 1;
			break;
		case (1):
			WS2812_RESET();
			WS2812_Manda_Trama();
			salida = 1;
			break;
		default:
			// Si se presiona cualquier otra tecla no pasa nada
			break;
		}
	} while (((m == 0) | (m == 1)) & (salida == 0));

	return m; //Devuelvo el valor m que determina el modo de juego
}

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
