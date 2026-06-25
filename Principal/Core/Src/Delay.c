/*
 * Delay.c
 *
 *  Created on: 25 jun 2026
 *      Author: Administrador
 */
#include "Delay.h"
#include "main.h"

void Delay(uint32_t retardo_ms)
{
    uint32_t tiempo_inicio = HAL_GetTick();  // ✅ local variable inside a function

    while ((HAL_GetTick() - tiempo_inicio) < retardo_ms)
    {
        // No hace nada.
    }
}
