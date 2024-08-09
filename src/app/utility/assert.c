#include "assert.h"

#include <stdbool.h>

#define LOG_IMMEDIATE(...)

void asserted (void)
{
#if defined(TESTING)
// Ceedling unit test support
#include "CException.h"
    Throw(0);
#else
#ifdef DEBUG
    // Debug build, hit a breakpoint to allow inspection of stack
    LOG_IMMEDIATE("ASSERT", sizeof("ASSERT"));
    asm("BKPT #0");
#else
    // TODO: runtime do something
    LOG_IMMEDIATE("ASSERT", sizeof("ASSERT"));
#endif // DEBUG
    // Shouldn't reach here but just in case force watchdog reset
    // TODO force watchdog reset
    // TODO - we should add a method to report a message via shared mem that can be reported later
#endif // TEST
}
