#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>
#include <string.h>

// Macro for performing static assertions, depending on langauge:
//    static_assert for C++
//    _Static_assert for C
// see https://stackoverflow.com/a/54993033
#ifdef __cplusplus
#ifndef _Static_assert
#define _Static_assert static_assert /* `static_assert` is part of C++11 or later */
#endif
#endif
#define STATIC_ASSERT(x, y) _Static_assert(x, y)

#ifdef TESTING
#include <stdio.h>

#ifdef TEST_LOG
#define LOG_DEBUG(args...)                                      \
    printf("ERROR: %s:%s:%d - ", __FILE__, __func__, __LINE__); \
    printf(args)
#else
#define LOG_DEBUG(...)
#endif // TEST_DEBUG

#else
#define LOG_DEBUG(args...)
#endif // TESTING

#define KEYWORD_IF_NULL(_ptr_, _kw_)       \
    if ((_ptr_) == NULL)                   \
    {                                      \
        LOG_DEBUG("%s is NULL\n", #_ptr_); \
        _kw_;                              \
    }

#define KEYWORD_IF_TRUE(statement, _kw_)       \
    if ((statement) == true)                   \
    {                                          \
        LOG_DEBUG("%s is true\n", #statement); \
        _kw_;                                  \
    }

#define KEYWORD_IF_FALSE(statement, _kw_)       \
    if ((statement) == false)                   \
    {                                           \
        LOG_DEBUG("%s is false\n", #statement); \
        _kw_;                                   \
    }

#define GOTO_EXIT_IF_NULL(_ptr_) KEYWORD_IF_NULL(_ptr_, goto exit)

#define GOTO_EXIT_IF_TRUE(_statement_) KEYWORD_IF_TRUE(_statement_, goto exit)

#define GOTO_EXIT_IF_FALSE(_statement_) KEYWORD_IF_FALSE(_statement_, goto exit)

#define GOTO_LABEL_IF_FALSE(_statement_, _label_) KEYWORD_IF_FALSE(_statement_, goto _label_)

#define RETURN_IF_TRUE(_statement_) KEYWORD_IF_TRUE(_statement_, return)

#define RETURN_IF_FALSE(_statement_) KEYWORD_IF_FALSE(_statement_, return)

#define RETURN_IF_NULL(_statement_) KEYWORD_IF_NULL(_statement_, return)

#define CONTINUE_IF_TRUE(_statement_) KEYWORD_IF_TRUE(_statement_, continue)

#define CONTINUE_IF_FALSE(_statement_) KEYWORD_IF_FALSE(_statement_, continue)

#define CONTINUE_IF_NULL(_statement_) KEYWORD_IF_NULL(_statement_, continue)

#define CHECK_AND_CALL_BOOL_CALLBACK(_cb_, ...) \
    cbStatus = true;                            \
    if (_cb_ != NULL)                           \
    {                                           \
        cbStatus = _cb_(__VA_ARGS__);           \
    }                                           \
    else                                        \
    {                                           \
        LOG_DEBUG("%s is NULL\n", #_cb_)        \
    }

#define CHECK_AND_CALL_VOID_CALLBACK(_cb_, ...) \
    if (_cb_ != NULL)                           \
    {                                           \
        _cb_(__VA_ARGS__);                      \
    }                                           \
    else                                        \
    {                                           \
        LOG_DEBUG("%s is NULL\n", #_cb_)        \
    }

/**
 * @brief Get the number of elements in an array
 *
 */
#define ARRAY_SIZE(a) ((uint32_t)(sizeof(a) / sizeof(*(a))))

/**
 * @brief Not type safe min function
 *
 */
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

/**
 * @brief Avoid unused variable warnings
 *
 */
#define UNUSED_ASSERT(_x_) ((void)(_x_))

// These macros allow simultaneous creation of an enum and a string
// array matching those enums with both deriving from the same place.
// It relies on the preprocessor to keep them in sync.
// Instructions for use:
//   https://stackoverflow.com/a/10966395
// #define GENERATE_ENUM(ENUM)       ENUM,
// #define GENERATE_STRING(STRING)   #STRING,

/**
 * @brief For a given enum _type_ and enum _name_ create a function prototype for a function that converts a string to
 * the enum and an extern array decleration.
 *
 * Extern lets us defin an array in a .c file but let users include it via a .h file instead of having to call a getter
 * function
 *
 */
#define STRING2ENUM_PROTOTYPE(_type_, _name_)                                \
    _type_                   get##_name_##FromString(const char *const str); \
    extern const char *const _name_##_strings[]

/**
 * @brief For a given enum _type_ and enum _name_ create a function that converts a string to the enum
 *
 * Expects that you are using the GENERATE_ENUM and GENERATE_STRING methods for creating enum -> string mappings
 *
 */
#define STRING2ENUM_FUNC(_type_, _name_)                                  \
    _type_ get##_name_##FromString(const char *const str)                 \
    {                                                                     \
        _type_ found = _name_##_INVALID;                                  \
        int    len   = strnlen(str, 20);                                  \
                                                                          \
        for (_type_ iter = _name_##_START; iter < _name_##_COUNT; iter++) \
        {                                                                 \
            if (!strcmp(_name_##_strings[iter], str))                     \
            {                                                             \
                found = iter;                                             \
                break;                                                    \
            }                                                             \
        }                                                                 \
                                                                          \
        return found;                                                     \
    }

/**
 * @brief Gives the size of a struct member
 *
 */
#define MEMBER_SIZE(type, member) sizeof(((type *)0)->member)

const char *lltoa(int64_t val, char *buf, uint32_t buf_size, int base);
const char *llutoa(uint64_t val, char *buf, uint32_t buf_size, int base);

#endif // KB_UTILITY_H
