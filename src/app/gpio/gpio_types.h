#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

typedef enum
{
    GPIO_START = 0,
    GPIO_A     = GPIO_START,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_E,
    GPIO_F,
    GPIO_G,
    GPIO_NUM,
    GPIO_INVALID,
} GPIOx_t;

#endif