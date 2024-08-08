#ifndef LED_H
#define LED_H

#include "LED_types.h"

void LEDsInit(void);
void LEDOn(const LEDID_t ID);
void LEDOff(const LEDID_t ID);

#endif