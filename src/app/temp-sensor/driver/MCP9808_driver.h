#ifndef MCP9808_DRIVER_H
#define MCP9808_DRIVER_H

#include "MCP9808_types.h"

void MCP9808Init(const MCP9808_t *MCP9808_handle);
void MCP9808_tempLimitsSet(MCP9808_t *MCP9808_handle, const double upperTempLimit, const double lowerTempLimit, const double criticalTempLimit);
void MCP9808_upperTempLimitSet(MCP9808_t *MCP9808_handle, const double upperTempLimit);
void MCP9808_lowerTempLimitSet(MCP9808_t *MCP9808_handle, const double lowerTempLimit);
void MCP9808_criticalTempLimitSet(MCP9808_t *MCP9808_handle, const double criticalTempLimit);
void MCP9808_ambientTempGet(MCP9808_t *MCP9808_handle);

#endif