#include "temp_sensor_module.h"
#include "MCP9808_driver.h"
#include <stddef.h>

void tempSensorModuleInit(void)
{
    MCP9808Init(NULL);
}