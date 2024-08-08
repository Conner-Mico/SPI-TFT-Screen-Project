#include "LED_types.h"
#include "clock.h"
#include "application.h"
#include "LED.h"
#include "stm32l4xx_hal.h"

// application init function definition
void applicationInit(void)
{
    HAL_Init();
    systemClocksConfig();
    LEDsInit();
}

// application run function definition
void applicationRun(void)
{
    while (1) {
        LEDOn(LED_ID_BLINKY);
        HAL_Delay(500);
        LEDOff(LED_ID_BLINKY);
        HAL_Delay(500);
    }
}