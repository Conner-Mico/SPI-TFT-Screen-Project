#include "MCP9808_driver.h"
#include "MCP9808_regs.h"
#include "MCP9808_types.h"
#include "assert.h"
#include <stdint.h>

// This is where all of the hal function calls live

static void MCP9808_registerPointerWrite(const MCP9808_WritePointer_t writePtr)
{
    // I2C Write to Register Pointer
}


static void MCP9808_configRegisterRead(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send configuration pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction
}

static void MCP9808_configRegisterWrite(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send configuration pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

static void MCP9808_upperTempRegisterRead(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send upper temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction
}

static void MCP9808_upperTempRegisterWrite(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send upper temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

static void MCP9808_lowerTempRegisterRead(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send lower temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction
}

static void MCP9808_lowerTempRegisterWrite(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send lower temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

static void MCP9808_criticalTempRegisterRead(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send critical temp pointer over I2C
    // Send address byte over I2C
    // Read MSB over I2C
    // Read LSB over I2C
    // End I2C transaction
}

static void MCP9808_criticalTempRegisterWrite(void)
{
    // Start I2C transaction
    // Send address byte over I2C
    // Send critical temp pointer over I2C
    // Send MSB over I2C
    // Send LSB over I2C
    // End I2C transaction
}

void MCP9808_setTempLimits(const MCP9808_t *MCP9808_handle, const uint16_t upperTempLimit, const uint16_t lowerTempLimit, const uint16_t criticalTempLimit)
{

}




void MCP9808_init(const MCP9808_t *MCP9808_handle)
{
    // Init I2C bus
    // 
}