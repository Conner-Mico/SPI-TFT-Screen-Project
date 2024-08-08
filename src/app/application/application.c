#include "clock.h"
#include "application.h"
#include "LED.h"
#include "stm32l4xx_hal.h"

// Do a struct initialization with the approriate values for the pin
static GPIO_InitTypeDef blinkLEDPinInit = {
                                            .Pin = GPIO_PIN_13,
                                            .Mode = GPIO_MODE_OUTPUT_PP,
                                            .Pull = GPIO_PULLDOWN,
                                            .Speed = GPIO_SPEED_FREQ_HIGH,
                                            .Alternate = 0, 
                                        };

// application init function definition
void applicationInit(void)
{
    HAL_Init();
    systemClockConfig();
    LEDinit();
    
}

// application run function definition
void applicationRun(void)
{
    while (1) {
        LEDon();
        HAL_Delay(500);
        LEDoff();
        HAL_Delay(500);
    }
}