#ifndef FT6206_TYPES_H
#define FY6206_TYPES_H

#include "stm32l4xx_hal.h"
#include <stdint.h>

typedef struct
{

} FT6206_ConfigRegister_Config_t;

typedef struct
{
    FT6206_ConfigRegister_Config_t config;
    uint16_t manufacturerID;
    uint8_t deviceID;
    uint8_t revision;

} FT6206_t;


#endif
