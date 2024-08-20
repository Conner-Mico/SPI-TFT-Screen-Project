#include "LED.h"
#include "LED_types.h"
#include "assert.h"
#include "clock.h"
#include "gpio_types.h"
#include "stm32l4xx_hal.h"

// Do a struct initialization with the approriate values for the pin

static LED_t blinkLED = {
    .GPIOInit.Pin       = GPIO_PIN_5,
    .GPIOInit.Mode      = GPIO_MODE_OUTPUT_PP,
    .GPIOInit.Pull      = GPIO_PULLDOWN,
    .GPIOInit.Speed     = GPIO_SPEED_FREQ_HIGH,
    .GPIOInit.Alternate = 0,

    .GPIOPtr            = GPIOA,
    .GPIOx              = GPIO_A,
};

static LED_t *LEDs[LED_ID_NUM] = {
    [LED_ID_BLINKY] = &blinkLED,
};

/**
 * @brief
 *
 * @param LED
 */
static void LEDInit (const LEDID_t ID)
{
    assert(ID < LED_ID_NUM);

    RCC_GPIO_ClockInit(LEDs[ID]->GPIOx);
    HAL_GPIO_Init(LEDs[ID]->GPIOPtr, &LEDs[ID]->GPIOInit); // Initialize GPIO
}

void LEDsInit (void)
{
    for (LEDID_t ID = LED_ID_START; ID < LED_ID_NUM; ID++)
    {
        LEDInit(ID);
    }
}

/**
 * @brief
 *
 * @param LED
 */
void LEDOn (const LEDID_t ID)
{
    HAL_GPIO_WritePin(LEDs[ID]->GPIOPtr, LEDs[ID]->GPIOInit.Pin, GPIO_PIN_SET); // Set pin high
}

/**
 * @brief
 *
 * @param LED
 */
void LEDOff (const LEDID_t ID)
{
    HAL_GPIO_WritePin(LEDs[ID]->GPIOPtr, LEDs[ID]->GPIOInit.Pin, GPIO_PIN_RESET); // Set pin low
}

/**
 * @brief
 *
 * @param LED
 */
void LEDToggle (const LEDID_t ID)
{
    HAL_GPIO_TogglePin(LEDs[ID]->GPIOPtr, LEDs[ID]->GPIOInit.Pin); // Toggle pin
}