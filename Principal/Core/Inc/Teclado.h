/*
 * Teclado.h
 *
 *  Created on: 12 jun 2026
 *      Author: Administrador
 */

#ifndef INC_TECLADO_H_
#define INC_TECLADO_H_
#define C1_Pin GPIO_PIN_0
#define C2_Pin GPIO_PIN_1
#define C3_Pin GPIO_PIN_2
#define C4_Pin GPIO_PIN_3
#define R1_Pin GPIO_PIN_4
#define R2_Pin GPIO_PIN_5
#define R3_Pin GPIO_PIN_6
#define R4_Pin GPIO_PIN_7
#define BotonMatriz GPIOD
//estructuras ej typedef

//prototipos
void Teclado(void);
void Barrido(void);
void Chequeo(void);

#endif /* INC_TECLADO_H_ */
