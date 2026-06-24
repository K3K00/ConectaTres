/*
 * Juego.h
 *
 *  Created on: 18 jun 2026
 *      Author: Administrador
 */

#ifndef INC_JUEGO_H_
#define INC_JUEGO_H_
#include "main.h"

void SeleccionarColumna(void);
void Gravedad(void);
void juega_CPU(void);
int verificar_victoria(void);
void animacion_victoria(int resultado);

#endif /* INC_JUEGO_H_ */
