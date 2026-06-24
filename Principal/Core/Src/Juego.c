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
#include "stdlib.h"
#include "Animaciones.h"
//---------------------------------------------------------------------------------------------------
#define FILAS 8
#define COLUMNAS 4
uint8_t columna[4] = { 31, 27, 23, 19 }; //Vector que toma los valores de los leds que estan mas altos
//static int i = 0;
extern int resultado;
extern int modo;
//----------------------------------------------------------------------------------------------
extern int jugador_actual; // Arranca el Jugador 1
//----------------------------------------------------------------------------------------------
int indice_columna = 0; // Columna seleccionada actualmente (0 a 3)
static int jugada_confirmada = 0;
//-----------------------------------------------------------------------------------------------
static const uint8_t TABLERO_LEDS[8][4] = { { 31, 27, 23, 19 }, // Fila 0 (Techo)
		{ 30, 26, 22, 18 }, // Fila 1
		{ 29, 25, 21, 17 }, // Fila 2
		{ 28, 24, 20, 16 }, // Fila 3
		{ 15, 11, 7, 3 },  // Fila 4
		{ 14, 10, 6, 2 },  // Fila 5
		{ 13, 9, 5, 1 },  // Fila 6
		{ 12, 8, 4, 0 }   // Fila 7 (Piso)
};
static int tablero[8][4] = { 0 };  //0=vacio  1=jugado1    2=jugador2
//-----------------------------------------------------------------------------------------------
//static int resultado = 0;
//-----------------------------------------------------------------------------------------------

static void cambiar_jugador(void) {

	switch (modo) {
	case 0:
		if (jugador_actual == 1) {
			jugador_actual = 2;
		} else {
			jugador_actual = 1;
		}
		break;
	case 1:
		if (jugador_actual == 1) {
			jugador_actual = 3;	// CPU = 3
		} else {
			jugador_actual = 1;
		}

	}
}
//Funcion para cambiar de jugador

void SeleccionarColumna(void)  //Arranca con el jugador 1
{
	int tecla = 0;
	jugada_confirmada = 0;
	uint8_t r = (jugador_actual == 1) ? 50 : 0; // Si jugador_actual=1 le asigno 50 a r
	uint8_t b = (jugador_actual == 2) ? 50 : 0;
	uint8_t g = (jugador_actual == 3) ? 50 : 0;
	do {
		if ((jugador_actual == 1) | (jugador_actual == 2)) {
			Barrido();
			tecla = ObtenerTecla();

			switch (tecla) {
			case (1):  //Apago el led y me muevo a la derecha
				WS2812_LED_N_Color(columna[indice_columna], 0, 0, 0);
				if (indice_columna < 3) {
					indice_columna++;
				}
				HAL_Delay(200);
				break;

			case (13): //Apago el led y me muevo a la izquierda
				WS2812_LED_N_Color(columna[indice_columna], 0, 0, 0);
				if (indice_columna > 0) {
					indice_columna--;
				}
				HAL_Delay(200);
				break;

			case (8):
				jugada_confirmada = 1;
				HAL_Delay(200);
				break;
			default:
				break;
			}
		} else {
			juega_CPU();
		}
		WS2812_LED_N_Color(columna[indice_columna], r, g, b);
		WS2812_Manda_Trama();

	} while (jugada_confirmada == 0);

}

void juega_CPU(void) {
	jugada_confirmada = 0;

	while (jugada_confirmada == 0) { //Si la jugada no está confirmada que busque un lugar vacio
		indice_columna = rand() % 4;
		WS2812_LED_N_Color(columna[indice_columna], 0, 0, 0); //Elijo una columna al azar
		if (tablero[0][indice_columna] == 0) {
			jugada_confirmada = 1;
		}
	}

}

void Gravedad(void) {
	uint8_t r = (jugador_actual == 1) ? 50 : 0;
	uint8_t b = (jugador_actual == 2) ? 50 : 0;
	uint8_t g = (jugador_actual == 3) ? 50 : 0;
	int fila_destino = -1;

	for (int f = 0; f <= 7; f++) {              //Voy restando de a una fila
		if (tablero[f][indice_columna] == 0) {
			fila_destino = f; // Aca es donde frena la ficha
		} else {
			break;
		} // Freno porque esta llena
	}
	if (fila_destino == -1) { //Esto quiere decir que la columna esta llena inicialmente
		return;
	}
	for (int f = 0; f <= fila_destino; f++) { //Este for es para controlar el encendio y apagado de los leds
		WS2812_LED_N_Color(TABLERO_LEDS[f][indice_columna], r, g, b);
		WS2812_Manda_Trama();
		HAL_Delay(80);
		if (f < fila_destino) {
			WS2812_LED_N_Color(TABLERO_LEDS[f][indice_columna], 0, 0, 0);
			WS2812_Manda_Trama();
		}
	}
	tablero[fila_destino][indice_columna] = jugador_actual;

	cambiar_jugador();
}

int verificar_victoria(void) {

	// --- HORIZONTAL (3 seguidas) ---
	//int resultado = 0;

	for (int f = 0; f < FILAS; f++) {                 // Recorre las 8 filas
		for (int c = 0; c < (COLUMNAS - 1); c++) {
			if (tablero[f][c] != 0 && tablero[f][c] == tablero[f][c + 1]
					&& tablero[f][c] == tablero[f][c + 2]) {
				resultado = tablero[f][c]; // Devuelve el numero que hay en la casilla
				return resultado;
			}
		}
	}

	// ---  VERTICAL (3 seguidas) ---
	for (int c = 0; c < COLUMNAS; c++) {           // Recorre las 4 columnas
		for (int f = 0; f < (FILAS - 2); f++) {
			if (tablero[f][c] != 0 && tablero[f][c] == tablero[f + 1][c]
					&& tablero[f][c] == tablero[f + 2][c]) {
				resultado = tablero[f][c]; // Devuelve el numero que hay en la casilla
				return resultado;
			}
		}
	}

	// ---DIAGONAL HACIA ABAJO---
	for (int f = 0; f < (FILAS - 2); f++) {
		for (int c = 0; c < (COLUMNAS - 2); c++) {
			if (tablero[f][c] != 0 && tablero[f][c] == tablero[f + 1][c + 1]
					&& tablero[f][c] == tablero[f + 2][c + 2]) {
				resultado = tablero[f][c];
				return resultado;
			}
		}
	}

	// ---  DIAGONAL HACIA ARRIBA ---
	for (int f = 2; f < FILAS; f++) {
		for (int c = 0; c < (COLUMNAS - 2); c++) {
			if (tablero[f][c] != 0 && tablero[f][c] == tablero[f - 1][c + 1]
					&& tablero[f][c] == tablero[f - 2][c + 2]) {
				resultado = tablero[f][c];
				return resultado;
			}
		}
	}

	resultado = 0; // No ganó nadie / Empate
	return resultado;
}

void animacion_victoria(int resultado) {

	switch (resultado) {
	case (0):
		WS2812_RESET();
		WS2812_Manda_Trama();
		empate();

		HAL_Delay(2000);
		break;
	case (1):
		WS2812_RESET();
		WS2812_Manda_Trama();

		ganaazul();

		HAL_Delay(2000);

		break;
	case (2):
		WS2812_RESET();
		WS2812_Manda_Trama();
		ganarojo();

		HAL_Delay(2000);

	case (3):
		WS2812_RESET();
		WS2812_Manda_Trama();
		ganacpu();

		HAL_Delay(2000);

		break;
	default:  //Resultado solo puede tomar tres valores
		break;
	}

	for (int f = 0; f <= (FILAS - 1); f++) {
		for (int c = 0; c <= (COLUMNAS - 1); c++) {
			tablero[f][c] = 0;
		}
	}

}
