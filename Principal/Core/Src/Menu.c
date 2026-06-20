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

static int m = 0;
static int salida = 0;
static int estadoprevio = 0;
static int tecla = 0;

void Inicio(void) {
	WS2812_LED_N_Color(0, 100, 0, 0);
	WS2812_Manda_Trama();
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

int Seleccion(int modo) { //Aca quiero presentar ambas imagenes para los 2 modos.
	//Realizo el barrido para ver que tecla se presiono
	estadoprevio = 4;

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

	do {
		Barrido();
		tecla = ObtenerTecla();
		switch (tecla) {
		case (4):
			if (estadoprevio == 16) {
				WS2812_RESET();
				WS2812_Manda_Trama();
				estadoprevio = 4;
			} else if (estadoprevio == 4) {
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

			m = 0; //estamos en el modo 1V1
			break;
		case (16):
			if (estadoprevio == 4) {
				WS2812_RESET();
				WS2812_Manda_Trama();
				estadoprevio = 16;
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
			} else if (estadoprevio == 16) {
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

			m = 1; //estamos en el modo 1VCPu
			break;
		default:
			if (tecla == 1) {
				salida = 1;
			}
			break;
		}
	} while (((m == 0) | (m == 1)) && (salida == 0));

	return m; //Devuelvo el valor m que determina el modo de juego
}

//int matriz [8][4];

//matriz[1][1] = 1;
