/*
 * Juego.c
 *
 *  Created on: 18 jun 2026
 *      Author: Administrador
 */

#include "Juego.h"
#include "ws2812b.h"
#include "Teclado.h"
#include "main.h"
#include "stdint.h"

uint8_t columna[4] = { 31, 27, 23, 19 };
int tecla = 0;
int i = 0;

void TurnoJugador1(void) {
	//Selecciono la casilla que quiero utilizar
	WS2812_RESET();
	WS2812_Manda_Trama();
	do {
		Barrido();
		tecla = ObtenerTecla();
		if (tecla == 1)
			i++;
		else if (tecla == 13)
			i--;
		WS2812_LED_N_Color(columna[i], 50, 0, 0);
		WS2812_Manda_Trama();
		HAL_Delay(500);
		WS2812_LED_N_Color(columna[i], 0, 0, 0);
		WS2812_Manda_Trama();
		HAL_Delay(500);
	} while (ObtenerTecla() == 8);

}
void TurnoJugador2(void) {

}
void TurnoCPU(void) {

}

void Gravedad(void) {

}

void Ganador(void) {

}
