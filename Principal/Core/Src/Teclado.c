/*
 * Teclado.c
 *
 *  Created on: 12 jun 2026
 *      Author: Administrador
 */
#include "Teclado.h"
#define Periodo 500


int fila = 0;
static uint32_t Tiempo = 0;

void Barrido(void){ //Barro todas las filas del teclado
	// Seteo primero C1=1 y el resto en 0
	HAL_GPIO_WritePin(BotonMatriz, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(BotonMatriz, R2_Pin, GPIO_);
	HAL_GPIO_WritePin(BotonMatriz, R3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(BotonMatriz, R4_Pin, GPIO_PIN_RESET);

	//Mientras el HAL_GetTick-Tiempo sea menor al Periodo, entonces voy a ir verificando cada columna
	do{
		//Leo cada columna por separado de la fila 0
		fila = 0;
		Chequeo();
		Tiempo = HAL_GetTick();
	} while(HAL_GetTick() - Tiempo < Periodo);


}

int Chequeo(int fila){ //Chequeo si alguno de los botones esta presionado
	if (HAL_GPIO_ReadPin(BotonMatriz, C1_Pin))
	return (fila * 4) + 1;
	if (HAL_GPIO_ReadPin(BotonMatriz, C2_Pin))
	return (fila * 4) + 1;
	if (HAL_GPIO_ReadPin(BotonMatriz, C3_Pin))
	return (fila * 4) + 1;
	if (HAL_GPIO_ReadPin(BotonMatriz, C4_Pin))
	return (fila * 4) + 1;
}
