#ifndef FT6206_DRIVER_H
#define FT6206_DRIVER_H

#include "FT6206_types.h"

void FT6206Init(const FT6206_t *FT6206_handle);
void FT6202_configRegisterWrite(const FT6206_t *FT6206_handle);
void FT6202_configRegisterRead(const FT6206_t *FT6206_handle);
void FT6202_dataRegisterWrite(const FT6206_t *FT6206_handle);
void FT6202_dataRegisterRead(const FT6206_t *FT6206_handle);


#endif