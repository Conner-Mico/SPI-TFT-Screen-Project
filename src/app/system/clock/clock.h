#ifndef CLOCK_H
#define CLOCK_H

#include "gpio_types.h"
#include "stm32l4xx_hal.h"
#include <stdbool.h>

HAL_StatusTypeDef systemClocksConfig(void);
void              RCC_GPIO_ClockInit(const GPIOx_t GPIOx);

#endif