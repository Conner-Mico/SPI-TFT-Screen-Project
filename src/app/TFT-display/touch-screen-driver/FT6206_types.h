#ifndef FT6206_TYPES_H
#define FY6206_TYPES_H

#include "stm32l4xx_hal.h"
#include <stdint.h>

typedef enum
{
    FT6206_MOVE_UP,
    FT6206_MOVE_RIGHT,
    FT6206_MOVE_DOWN,
    FT6206_MOVE_LEFT,
    FT6206_ZOON_IN,
    FT6206_ZOOM_OUT,
    FT6206_NONE

} FT6206_Gestures_t;

typedef enum
{
    PRESS_DOWN,
    LIFT_UP,
    CONTACT,
    NONE

} FT6206_EventFlags_t;

typedef union
{
    struct FT6206_types
    {
        /* data */
    };
    

} FT6206_ConfigRegister_Config_t;

typedef struct 
{
    FT6206_Gestures_t gesture;
    FT6206_EventFlags_t eventFlagX;
    FT6206_EventFlags_t eventFlagY;
    uint16_t positionX;
    uint16_t positionY;
    uint8_t touchWeight;
    uint8_t touchArea;

} FT6206_TouchEvent_t;

typedef struct
{
    FT6206_ConfigRegister_Config_t config;
    bool inHibernateMode;//If false, device is 
    bool inPollingMode; //If false, IC is in trigger mode
    FT6206_TouchEvent_t touchEvent;
    uint16_t manufacturerID;
    uint8_t deviceID;
    uint8_t revision;

    I2C_HandleTypeDef I2CHandle;

} FT6206_t;

#endif
