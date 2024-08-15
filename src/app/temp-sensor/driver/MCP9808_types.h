#ifndef MCP9808_TYPES_H
#define MCP9808_TYPES_H

#include <stdint.h>
#include "MCP9808_driver.h"
//#include "stm32l4xx_hal_i2c.h"

typedef enum
{
    MCP9808_SIGN_START = 0,
    MCP9808_SIGN_POSITIVE = MCP9808_SIGN_START,
    MCP9808_SIGN_NEGATIVE,
    MCP9808_SIGN_NUM,
    MCP9808_SIGN_INVALID,
} MCP9808_Sign_t;

typedef enum
{
    MCP9808_RESOLUTION_START = 0,
    MCP9808_RESOLUTION_ = MCP9808_RESOLUTION_START,
    MCP9808_RESOLUTION_0_5_CELSIUS,
    MCP9808_RESOLUTION_0_25_CELSIUS,
    MCP9808_RESOLUTION_0_125_CELSIUS,
    MCP9808_RESOLUTION_0_0625_CELSIUS,
} MCP9808_Resolution_t;

typedef enum
{
    MCP9808_WRITE_POINTER_START,
    MCP9808_WRITE_POINTER_RFU = MCP9808_WRITE_POINTER_START,
    MCP9808_WRITE_POINTER_CONFIG,
    MCP9808_WRITE_POINTER_ALERT_TEMP_UPPER,
    MCP9808_WRITE_POINTER_ALERT_TEMP_LOWER,
    MCP9808_WRITE_POINTER_ALERT_TEMP_CRITICAL,
    MCP9808_WRITE_POINTER_AMBIENT_TEMP,
    MCP9808_WRITE_POINTER_MANUFACTURER_ID,
    MCP9808_WRITE_POINTER_DEVICE_ID_REVISION,
    MCP9808_WRITE_POINTER_RESOLUTION,
    MCP9808_WRITE_POINTER_NUM,
    MCP9808_WRITE_POINTER_INVALID,
} MCP9808_WritePointer_t;

typedef struct
{
    uint16_t                                : 5;
    uint16_t hysteresis                     : 2;
    uint16_t shutdown                       : 1;
    uint16_t criticalTempRegLock            : 1;
    uint16_t upperLowerTempWindowRegLock    : 1; 
    uint16_t interruptClear                 : 1;
    uint16_t alertOutputStatus              : 1;
    uint16_t alertOutputControl             : 1; 
    uint16_t alertOutputSelect              : 1;
    uint16_t alertOutputPolarity            : 1;
    uint16_t alertOutputMode                : 1;
} MCP9808_ConfigRegister_Config_t;

typedef struct
{
    uint16_t                    : 3;
    uint16_t sign               : 1;
    uint16_t temperatureLimit   : 10;
    uint16_t                    : 2;
} MCP9808_UpperTemperatureLimit_t;

typedef struct
{
    uint16_t                    : 3;
    uint16_t sign               : 1;
    uint16_t temperatureLimit   : 10;
    uint16_t                    : 2;
} MCP9808_LowerTemperatureLimit_t;

typedef struct
{
    uint16_t                    : 3;
    uint16_t sign               : 1;
    uint16_t temperatureLimit   : 10;
    uint16_t                    : 2;
} MCP9808_CriticalTemperatureLimit_t;

typedef struct
{
    uint16_t ambientVsCritTemp  : 1;
    uint16_t ambientVsUpperTemp : 1;
    uint16_t ambientVsLowerTemp : 1;
    uint16_t sign               : 1;
    uint16_t ambientTemperature : 12;
} MCP9808_AmbientTemperature_t;

typedef struct
{
    MCP9808_ConfigRegister_Config_t     config;
    MCP9808_UpperTemperatureLimit_t     upperTemp;
    MCP9808_LowerTemperatureLimit_t     LowerTemp;
    MCP9808_CriticalTemperatureLimit_t  criticalTemp;
    MCP9808_AmbientTemperature_t        ambientTemp;
    uint16_t                            manufacturerID;
    uint8_t                             deviceID;
    uint8_t                             revision;
    uint8_t                             resolution;
} MCP9808_t;
#endif