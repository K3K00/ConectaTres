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
#include "Animaciones.h"

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


