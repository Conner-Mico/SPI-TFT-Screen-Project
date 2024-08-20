#ifndef LED_TYPES_H
#define LED_TYPES_H

#include "gpio_types.h"
#include "stm32l4xx_hal.h"

typedef struct
{

    GPIO_TypeDef    *GPIOPtr;
    GPIO_InitTypeDef GPIOInit;
    GPIOx_t          GPIOx;
} LED_t;

typedef enum
{
    LED_ID_START  = 0,
    LED_ID_BLINKY = LED_ID_START,
    LED_ID_NUM,
    LED_ID_INVALID,
} LEDID_t;

#endif
