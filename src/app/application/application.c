#include "clock.h"
#include "application.h"
#include "stm32l4xx_hal.h"

// Do a struct initialization with the approriate values for the pin
static GPIO_InitTypeDef blinkLEDPinInit;

// application init function definition
void applicationInit(void)
{
    HAL_Init();
    systemClockConfig();
    
}

// application run function definition
void applicationRun(void)
{
    while (1) {
    
    }
}