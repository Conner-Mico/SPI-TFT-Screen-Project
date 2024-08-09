# Describes the LL static library
list(
    APPEND
    LL_SOURCE
    stm32l4xx_ll_crs.c
    stm32l4xx_ll_pwr.c
    stm32l4xx_ll_crc.c
    stm32l4xx_ll_opamp.c
    stm32l4xx_ll_comp.c
    stm32l4xx_ll_rng.c
    stm32l4xx_ll_adc.c
    stm32l4xx_ll_sdmmc.c
    stm32l4xx_ll_pka.c
    stm32l4xx_ll_lpuart.c
    stm32l4xx_ll_dac.c
    stm32l4xx_ll_dma.c
    stm32l4xx_ll_rcc.c
    stm32l4xx_ll_spi.c
    stm32l4xx_ll_swpmi.c
    stm32l4xx_ll_lptim.c
    stm32l4xx_ll_dma2d.c
    stm32l4xx_ll_utils.c
    stm32l4xx_ll_rtc.c
    stm32l4xx_ll_tim.c
    stm32l4xx_ll_usart.c
    stm32l4xx_ll_fmc.c
    stm32l4xx_ll_exti.c
    stm32l4xx_ll_i2c.c
    stm32l4xx_ll_gpio.c
    stm32l4xx_ll_usb.c
)

list(
    APPEND
    LL_INCLUDE
    .
    ../../cmsis/include/
    ../../system/
    ../../src/app/config/
    ../HAL/
)

add_library(LL STATIC ${LL_SOURCE})

target_include_directories(LL PUBLIC ${LL_INCLUDE})