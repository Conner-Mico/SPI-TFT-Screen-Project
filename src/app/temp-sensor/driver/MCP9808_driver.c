#include "MCP9808_driver.h"
#include "MCP9808_regs.h"
#include "MCP9808_types.h"
#include "assert.h"
#include "utility.h"
#include <stdint.h>

// This is where all of the hal function calls live

static void MCP9808_registerPointerWrite(const MCP9808_t *MCP9808_handle, const MCP9808_WritePointer_t writePtr)
{
    // I2C Write to Register Pointer
}


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

static void MCP9808_configRegisterWrite(const MCP9808_t *MCP9808_handle)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send configuration pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

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

static void MCP9808_lowerTempRegisterWrite(const MCP9808_t *MCP9808_handle, const double lowerTempLimit)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send lower temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

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

static void MCP9808_criticalTempRegisterWrite(const MCP9808_t *MCP9808_handle, const double criticalTempLimit)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send critical temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

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

void MCP9808_init(const MCP9808_t *MCP9808_handle)
{
    // Init I2C bus for MCP9808 handle
    // Init config register
}

void MCP9808_upperTempLimitSet(MCP9808_t *MCP9808_handle, const double upperTempLimit)
{
    // TODO(cbwolfe94): Add conversion from uint16_t to double
    //GOTO_EXIT_IF_TRUE(MCP9808_upperTempRegisterRead(MCP9808_handle) == upperTempLimit);

    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_ALERT_TEMP_UPPER);
    MCP9808_upperTempRegisterWrite(MCP9808_handle, upperTempLimit);

/* exit:
    return; */
}

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

void MCP9808_criticalTempLimitSet(MCP9808_t *MCP9808_handle, const double criticalTempLimit)
{
    // TODO(cbwolfe94): Add temp conversion from uint16_t to double
    // GOTO_EXIT_IF_TRUE(MCP9808_criticalTempRegisterRead(MCP9808_handle) == lowerTempLimit);

    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_ALERT_TEMP_CRITICAL);
    MCP9808_criticalTempRegisterWrite(MCP9808_handle, criticalTempLimit);

    // TODO(cbwolfe94): Add conversion from double to tempLimitReg 
    // MCP9808_handle->criticalTemp.tempLimitReg = criticalTempLimit;    
}

void MCP9808_tempLimitsSet(MCP9808_t *MCP9808_handle, const double upperTempLimit, const double lowerTempLimit, const double criticalTempLimit)
{
    MCP9808_upperTempLimitSet(MCP9808_handle, upperTempLimit);
    MCP9808_lowerTempLimitSet(MCP9808_handle, lowerTempLimit);
    MCP9808_criticalTempLimitSet(MCP9808_handle, criticalTempLimit);
}

uint16_t MCP9808_ambientTempGet(MCP9808_t *MCP9808_handle)
{
    MCP9808_registerPointerWrite(MCP9808_handle, MCP9808_WRITE_POINTER_AMBIENT_TEMP);
    // TODO(cbwolfe94): Add conversion from ambient temp register to actual ambient temperature
    // MCP9808_ambientTempRegisterRead(MCP9808_handle);

    // Assign result of MCP9808_ambientTempRegisterRead to ambientTemp struct member
    return 0;
}