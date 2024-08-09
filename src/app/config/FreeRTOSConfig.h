// clang-format off
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#if defined(__GNUC__) || defined(__ICCARM__)
/* Important: put #includes here unless they are also meant for the assembler.
 */
#include <stdint.h>
void assert_triggered(const char *file, uint32_t line);
#endif

#if defined(__ICCARM__)
#include <cmsis_compiler.h>
#endif

#define configUSE_PREEMPTION                            1
#define configUSE_IDLE_HOOK                             1
#define configUSE_TICK_HOOK                             1
#define configSUPPORT_STATIC_ALLOCATION                 1
#define configSUPPORT_DYNAMIC_ALLOCATION                0
#define configPRIO_BITS                                 3
#define configCPU_CLOCK_HZ                              (48000000)
#define configTICK_RATE_HZ                              ((TickType_t)1000)
#define configMAX_PRIORITIES                            (5)
#define configMINIMAL_STACK_SIZE                        ((uint16_t)128)
#define configTOTAL_HEAP_SIZE                           ((size_t)(1024))
#define configMAX_TASK_NAME_LEN                         (16)
#define configUSE_TRACE_FACILITY                        1
#define configUSE_16_BIT_TICKS                          0
#define configIDLE_SHOULD_YIELD                         1
#define configUSE_MUTEXES                               1
#define configQUEUE_REGISTRY_SIZE                       0
#define configCHECK_FOR_STACK_OVERFLOW                  1
#define configUSE_RECURSIVE_MUTEXES                     0
#define configUSE_MALLOC_FAILED_HOOK                    0
#define configUSE_COUNTING_SEMAPHORES                   0
#define configUSE_QUEUE_SETS                            1
#define configGENERATE_RUN_TIME_STATS                   0
#define configENABLE_BACKWARD_COMPATIBILITY             1
#define configRECORD_STACK_HIGH_ADDRESS                 1

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    4
/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         0x07
#define configMAX_SYSCALL_INTERRUPT_PRIORITY            (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY                 (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define FREERTOS_ADVANCED_CONFIG                        1

//Not used in original FreeRTOSConfig.h file
/////////////////////////////////////////////////////////////
#define configUSE_TICKLESS_IDLE                         0
#define configUSE_STATS_FORMATTING_FUNCTIONS            0
#define configUSE_PORT_OPTIMISED_TASK_SELECTION         0
#define configUSE_APPLICATION_TASK_TAG                  0
/////////////////////////////////////////////////////////////

#define configUSE_CO_ROUTINES                           0
#define configMAX_CO_ROUTINE_PRIORITIES                 (2)

#define configUSE_TIMERS                                1
#define configTIMER_TASK_PRIORITY                       (5)
#define configTIMER_QUEUE_LENGTH                        5
#define configTIMER_TASK_STACK_DEPTH                    (128)

#define INCLUDE_vTaskPrioritySet                        1
#define INCLUDE_uxTaskPriorityGet                       1
#define INCLUDE_vTaskDelete                             1
#define INCLUDE_vTaskSuspend                            1
#define INCLUDE_xResumeFromISR                          1
#define INCLUDE_vTaskDelayUntil                         0
#define INCLUDE_vTaskDelay                              1
#define INCLUDE_xTaskGetSchedulerState                  1
#define INCLUDE_xTaskGetCurrentTaskHandle               1
#define INCLUDE_uxTaskGetStackHighWaterMark             1
#define INCLUDE_xTaskGetIdleTaskHandle                  0
#define INCLUDE_xTimerGetTimerDaemonTaskHandle          0
#define INCLUDE_pcTaskGetTaskName                       0
#define INCLUDE_eTaskGetState                           1
#define INCLUDE_vTaskCleanUpResources                   0
#define INCLUDE_xTimerPendFunctionCall                  0

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
#define configASSERT(x)                                                                                                \
    if ((x) == 0) {                                                                                                    \
        taskDISABLE_INTERRUPTS();                                                                                      \
        for (;;)                                                                                                       \
            ;                                                                                                          \
    }

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names - or at least those used in the unmodified vector table. */

#define vPortSVCHandler         SVCall_Handler
#define xPortPendSVHandler      PendSV_Handler
#define xPortSysTickHandler     SysTick_Handler

/* Used when configGENERATE_RUN_TIME_STATS is 1. */
#if configGENERATE_RUN_TIME_STATS
extern void     vConfigureTimerForRunTimeStats(void);
extern uint32_t vGetRunTimeCounterValue(void);
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() vConfigureTimerForRunTimeStats()
#define portGET_RUN_TIME_COUNTER_VALUE() vGetRunTimeCounterValue()
#endif

#endif // FREERTOSCONFIG_H

// clang-format on
