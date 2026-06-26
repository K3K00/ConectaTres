/*
 * ws2812b.c
 *
 *  Created on: Oct 7, 2024
 *      Author: ALCIDES_RAMOS
 */

#include "ws2812b.h"

//matrix para almacenar datos del # led y RGB_Color
uint8_t LED_RGB_Color[led_num][4];
//matriz si se quiere guardar el brillo d elso led
uint8_t LED_BRILLO[led_num][4];
//tamaño buffer para almacener los PWM que saldran por DMA
#define trama_largo (24*led_num)+1+41 //si se coloca 0 al inicio y  41 al final(50us)
uint16_t PWM_Trama[trama_largo]; //  para ubicar un cero al final;

//carga un RGB_Color deseado al led desado
void WS2812_LED_N_Color(uint8_t LED_N, uint8_t rojo, uint8_t verde,
		uint8_t azul) {
	LED_RGB_Color[LED_N][0] = LED_N;
	LED_RGB_Color[LED_N][1] = verde;
	LED_RGB_Color[LED_N][2] = rojo;
	LED_RGB_Color[LED_N][3] = azul;

}
//  funcion para aplicar el brillo con la funcion gamma

void WS2812_Arma_trama() {
	uint32_t cont_led = 1;
	uint32_t RGB_Color = 0;

	for (uint16_t i = 0; i < led_num; i++) {
		RGB_Color = (((uint32_t) LED_RGB_Color[i][1] << 16)
				| ((uint32_t) LED_RGB_Color[i][2] << 8)
				| ((uint32_t) LED_RGB_Color[i][3]));

		for (int16_t i1 = 23; i1 >= 0; i1--) {
			if (RGB_Color & ((uint32_t) 1 << i1)) {
				PWM_Trama[cont_led] = PWM_1;  //valor del 1
			}
			else
				PWM_Trama[cont_led] = PWM_0; // valor del cero
			cont_led++;
		} //fin for i=23
	} //for i<led_num

	for (uint8_t i = 1; i <= 41; i++) {
		PWM_Trama[cont_led] = 0; //coloca 50 cero al final
		cont_led++;
	}
	PWM_Trama[0] = 0; //coloca un cero al inicio
}

void WS2812_Manda_Trama() {
	WS2812_Arma_trama();
	HAL_TIM_PWM_Start_DMA(& ws2812_timer, ws2812_canal, (uint32_t*) PWM_Trama,
			trama_largo);
	// HAL_Delay(1);
}

void WS2812_RESET() {

	for (uint8_t i = 0; i < led_num; i++) {
		LED_RGB_Color[i][0] = i;
		LED_RGB_Color[i][1] = 0;
		LED_RGB_Color[i][2] = 0;
		LED_RGB_Color[i][3] = 0;
	}
}

