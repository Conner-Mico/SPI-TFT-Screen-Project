#include "LED.h"
#include "stm32l4xx_hal_gpio.h"

static GPIO_InitTypeDef blinkLEDPinInit = {
                                            .Pin = GPIO_PIN_13,
                                            .Mode = GPIO_MODE_OUTPUT_PP,
                                            .Pull = GPIO_PULLDOWN,
                                            .Speed = GPIO_SPEED_FREQ_HIGH,
                                            .Alternate = 0, 
                                        };

// LED init function definition
void LEDinit(void)
{
    HAL_GPIO_Init(&blinkLEDPinInit);
}

// LED on function definition
void LEDon(void)
{
    HAL_GPIO_WritePin(GPIO_PIN_13, GPIO_PIN_SET); // Set pin high
}

// LED off function definition
void LEDoff(void)
{
    HAL_GPIO_WritePin(GPIO_PIN_13, GPIO_PIN_RESET); // Set pin low
}