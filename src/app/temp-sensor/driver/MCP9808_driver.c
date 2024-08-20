#include "MCP9808_driver.h"
#include "MCP9808_regs.h"
#include "MCP9808_types.h"
#include "assert.h"
#include "utility.h"
#include <stdint.h>

/**
 * @brief Writes writePtr to Register Pointer Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param writePtr Value to write to register pointer register
 */
static void MCP9808_registerPointerWrite(const MCP9808_t *MCP9808_handle, const MCP9808_WritePointer_t writePtr)
{
    // I2C Write to Register Pointer
}

/**
 * @brief Reads from the Config Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @return uint16_t 16 bit register value
 */
static uint16_t MCP9808_configRegisterRead(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send configuration pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction

    return 0;
}

/**
 * @brief Writes to the Config Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 */
static void MCP9808_configRegisterWrite(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send configuration pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

/**
 * @brief Reads from the Upper Temp Limit Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @return uint16_t 16 bit register value
 */
static uint16_t MCP9808_upperTempRegisterRead(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send upper temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction

    return 0;
}

/**
 * @brief Writes to the Upper Temp Limit Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param upperTempLimit Temp limit to be set
 */
static void MCP9808_upperTempRegisterWrite(const MCP9808_t *MCP9808_handle, const double upperTempLimit)
{
    // Convert double to uint16 to send over I2C
    // Start I2C transaction
    // Send address byte over I2C
    // Send upper temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

/**
 * @brief Reads from the Lower Temp Limit Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @return uint16_t 16 bit register value
 */
static uint16_t MCP9808_lowerTempRegisterRead(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send lower temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction

    return 0;
}

/**
 * @brief Writes to the Lower Temp Limit Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param lowerTempLimit Temp limit to be set
 */
static void MCP9808_lowerTempRegisterWrite(const MCP9808_t *MCP9808_handle, const double lowerTempLimit)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send lower temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

/**
 * @brief Reads from the Critical Temp Limit Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @return uint16_t 16 bit register value
 */
static uint16_t MCP9808_criticalTempRegisterRead(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send critical temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction
    
    return 0;
}

/**
 * @brief Writes to the Critical Temp Limit Register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param criticalTempLimit Temp limit to be set
 */
static void MCP9808_criticalTempRegisterWrite(const MCP9808_t *MCP9808_handle, const double criticalTempLimit)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send critical temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

/**
 * @brief Reads from the Ambient Temperature register
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @return uint16_t 16 bit register value
 */
static uint16_t MCP9808_ambientTempRegisterRead(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send ambient temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction

    return 0;
}

/**
 * @brief Initializes MCP9808 Temp Sensor
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 */
void MCP9808_init(const MCP9808_t *MCP9808_handle)
{
    // Init I2C bus for MCP9808 handle
    // Init config register
}

/**
 * @brief Sets new upper temp limit
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param upperTempLimit New upper temp limit to be set
 */
void MCP9808_upperTempLimitSet(MCP9808_t *MCP9808_handle, const double upperTempLimit)
{
    // TODO(cbwolfe94): Add conversion from uint16_t to double
    //GOTO_EXIT_IF_TRUE(MCP9808_upperTempRegisterRead(MCP9808_handle) == upperTempLimit);

    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_ALERT_TEMP_UPPER);
    MCP9808_upperTempRegisterWrite(MCP9808_handle, upperTempLimit);

/* exit:
    return; */
}

/**
 * @brief Sets new lower temp limit
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param lowerTempLimit 
 */
void MCP9808_lowerTempLimitSet(MCP9808_t *MCP9808_handle, const double lowerTempLimit)
{
    // TODO(cbwolfe94): Add temp conversion from uint16_t to double
    // GOTO_EXIT_IF_TRUE(MCP9808_lowerTempRegisterRead(MCP9808_handle) == lowerTempLimit);

    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_ALERT_TEMP_LOWER);
    MCP9808_lowerTempRegisterWrite(MCP9808_handle, lowerTempLimit);

    // TODO(cbwolfe94): Add conversion from double to tempLimitReg 
    // MCP9808_handle->lowerTemp.tempLimitReg = lowerTempLimit;

/* exit:
    return; */
}

/**
 * @brief Sets new critical temp limit
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param criticalTempLimit New critical temp limit to set
 */
void MCP9808_criticalTempLimitSet(MCP9808_t *MCP9808_handle, const double criticalTempLimit)
{
    // TODO(cbwolfe94): Add temp conversion from uint16_t to double
    // GOTO_EXIT_IF_TRUE(MCP9808_criticalTempRegisterRead(MCP9808_handle) == lowerTempLimit);

    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_ALERT_TEMP_CRITICAL);
    MCP9808_criticalTempRegisterWrite(MCP9808_handle, criticalTempLimit);

    // TODO(cbwolfe94): Add conversion from double to tempLimitReg 
    // MCP9808_handle->criticalTemp.tempLimitReg = criticalTempLimit;    
}

/**
 * @brief Sets new limits for upper, lower, and critical temp
 * 
 * @param MCP9808_handle MCP9808 handle pointer
 * @param upperTempLimit New upper temp limit to set
 * @param lowerTempLimit New lower temp limit to set
 * @param criticalTempLimit New critical temp limit to set
 */
void MCP9808_tempLimitsSet(MCP9808_t *MCP9808_handle, const double upperTempLimit, const double lowerTempLimit, const double criticalTempLimit)
{
    MCP9808_upperTempLimitSet(MCP9808_handle, upperTempLimit);
    MCP9808_lowerTempLimitSet(MCP9808_handle, lowerTempLimit);
    MCP9808_criticalTempLimitSet(MCP9808_handle, criticalTempLimit);
}

/**
 * @brief Gets ambient temperature
 * 
 * @param MCP9808_handle MCP9808 handle pointer 
 */
void MCP9808_ambientTempGet(MCP9808_t *MCP9808_handle)
{
    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_AMBIENT_TEMP);
    // TODO(cbwolfe94): Add conversion from ambient temp register to actual ambient temperature
    // MCP9808_ambientTempRegisterRead(MCP9808_handle);

    // Assign result of MCP9808_ambientTempRegisterRead to ambientTemp struct member
    // Convert ambientTemp struct member to ambientTempActual
}