#include "application.h"
#include "LED.h"
#include "LED_types.h"
#include "assert.h"
#include "clock.h"
#include "stm32l4xx_hal.h"

// application init function definition
void applicationInit (void)
{
    HAL_Init();
    assert(!systemClocksConfig());
    LEDsInit();
}

// application run function definition
void applicationRun (void)
{
    while (1)
    {
        LEDToggle(LED_ID_BLINKY);
        HAL_Delay(1000);
    }
}