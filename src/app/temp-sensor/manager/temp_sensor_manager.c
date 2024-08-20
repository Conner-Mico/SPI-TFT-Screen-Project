#include "temp_sensor_manager.h"
#include "temp_sensor_module.h"

void tempSensorManagerInit (void)
{
    // Task init
    tempSensorModuleInit();
}