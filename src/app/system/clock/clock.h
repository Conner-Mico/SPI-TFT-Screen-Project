#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>
#include "stm32l4xx_hal_def.h"
#include "gpio_types.h"

HAL_StatusTypeDef systemClocksConfig(void);
void RCC_GPIO_ClockInit(const GPIOx_t GPIOx);

#endif