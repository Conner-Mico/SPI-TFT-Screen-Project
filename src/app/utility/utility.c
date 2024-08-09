#include "utility.h"

/**
 * @brief convert long long value to string for printing
 * @param val
 * @param buffer initialize to 0
 * @param buf_size must be at least 64
 * @param base
 * @return char*
 */
const char *lltoa (int64_t val, char *buf, uint32_t buf_size, int base)
{
    int i    = 62;
    int sign = (val < 0);
    if (sign)
    {
        val = -val;
    }

    if (val == 0)
    {
        return "0";
    }

    for (; val && i; --i, val /= base)
    {
        buf[i] = "0123456789abcdef"[val % base];
    }

    if (sign)
    {
        buf[i--] = '-';
    }
    return &buf[i + 1];
}

const char *llutoa (uint64_t val, char *buf, uint32_t buf_size, int base)
{
    int i = 62;

    if (val == 0)
    {
        return "0";
    }

    for (; val && i; --i, val /= base)
    {
        buf[i] = "0123456789abcdef"[val % base];
    }

    return &buf[i + 1];
}