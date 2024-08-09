#ifndef ASSERT_H
#define ASSERT_H

#include "utility.h"

#if defined(DEBUG) || defined(UNIT_TEST_CEEDLING)
#include <stdbool.h>

void asserted(void);

// Trigger an assert if expression is false
#define assert(_expr_)  \
    {                      \
        if (!(_expr_))     \
        {                  \
            asserted(); \
        }                  \
    }
#else
#define assert(x)
#endif

/**
 * @brief Waits for either _expr_ to become false or _timeout_ to expire
 */
#define WAIT_TIMEOUT(_expr_, _timeout_)                     \
    {                                                       \
        unsigned int i;                                     \
        for (i = 0; (_expr_) == true && i < _timeout_; i++) \
            ;                                               \
        assert(i < _timeout_);                           \
    }

#endif
