#include <stdbool.h>
#include "stm32l476xx.h"
#include "stm32l4xx_hal_pwr_ex.h"
#include "stm32l4xx_hal_flash.h"
#include "stm32l4xx_hal_rcc.h"
#include "clock.h"

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

bool systemClockConfig(void)
{
    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
    {
        return false;
    }

    if (HAL_RCC_OscConfig(&RCC_OscInit) != HAL_OK)
    {
        return false;
    }

    if (HAL_RCC_ClockConfig(&RCC_ClkInit, FLASH_LATENCY_4) != HAL_OK)
    {
        return false;
    }

    return true;
}