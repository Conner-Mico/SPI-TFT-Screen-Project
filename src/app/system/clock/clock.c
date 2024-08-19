#include <stdbool.h>
#include "assert.h"
#include "stm32l4xx_hal.h"
#include "clock.h"
#include "gpio_types.h"

static RCC_OscInitTypeDef RCC_OscInit = { .OscillatorType       = RCC_OSCILLATORTYPE_HSI,
                                          .HSIState             = RCC_HSI_ON,
                                          .HSICalibrationValue  = RCC_HSICALIBRATION_DEFAULT,
                                          .PLL.PLLState         = RCC_PLL_ON,
                                          .PLL.PLLSource        = RCC_PLLSOURCE_HSI,
                                          .PLL.PLLM             = 1,
                                          .PLL.PLLN             = 10,
                                          .PLL.PLLP             = RCC_PLLP_DIV7,
                                          .PLL.PLLQ             = RCC_PLLQ_DIV2,
                                          .PLL.PLLR             = RCC_PLLR_DIV2,
                                        };

static RCC_ClkInitTypeDef RCC_ClkInit = { .ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2,
                                          .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK,
                                          .AHBCLKDivider = RCC_SYSCLK_DIV1,
                                          .APB1CLKDivider = RCC_HCLK_DIV1,
                                          .APB2CLKDivider = RCC_HCLK_DIV1,};

HAL_StatusTypeDef systemClocksConfig(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();

    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (HAL_RCC_OscConfig(&RCC_OscInit) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (HAL_RCC_ClockConfig(&RCC_ClkInit, FLASH_LATENCY_4) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

static bool RCC_Clock_CheckIfEnabled(const GPIOx_t GPIOx)
{
    bool res;

    assert(GPIOx < GPIO_NUM);

    switch (GPIOx)
    {
        case GPIO_A:
            res = __HAL_RCC_GPIOA_IS_CLK_ENABLED();
            break;

        case GPIO_B:
            res = __HAL_RCC_GPIOB_IS_CLK_ENABLED();
            break;

        case GPIO_C:
            res = __HAL_RCC_GPIOC_IS_CLK_ENABLED();
            break;

        case GPIO_D:
            res = __HAL_RCC_GPIOD_IS_CLK_ENABLED();
            break;

        case GPIO_E:
            res = __HAL_RCC_GPIOE_IS_CLK_ENABLED();
            break;

        case GPIO_F:
            res = __HAL_RCC_GPIOF_IS_CLK_ENABLED();
            break;

        case GPIO_G:
            res = __HAL_RCC_GPIOG_IS_CLK_ENABLED();
            break;
            
        default:
            res = false;
            break;
    }

    return res;
}

void RCC_GPIO_ClockInit(const GPIOx_t GPIOx)
{
    GOTO_EXIT_IF_TRUE(RCC_Clock_CheckIfEnabled(GPIOx));

    switch (GPIOx)
    {
        case GPIO_A:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;

        case GPIO_B:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;

        case GPIO_C:
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;

        case GPIO_D:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;

        case GPIO_E:
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;

        case GPIO_F:
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;

        case GPIO_G:
            __HAL_RCC_GPIOG_CLK_ENABLE();
            break;

        default:
            break;
    }

exit:
    return;

}