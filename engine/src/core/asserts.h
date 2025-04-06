#pragma once

#include "../defines.h"

#define PRIAXE_ASSERTIONS_ENABLED

#ifdef PRIAXE_ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __buildin_trap()
#endif

PRIAXE_API void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define PRIAXE_ASSERT(expr)                                     \
{                                                               \
    if(expr) { }                                                \
    else                                                        \
    {                                                           \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);\
        debugBreak();                                           \
    }                                                           \
}

#define PRIAXE_ASSERT_MSG(expr, message)                                \
{                                                                       \
    if(expr) { }                                                        \
    else                                                                \
    {                                                                   \
        report_assertion_failure(#expr, message, __FILE__, __LINE__);   \
        debugBreak();                                                   \
    }                                                                   \
}

#ifdef _DEBUG
#define PRIAXE_ASSERT_DEBUG(expr)                                       \
{                                                                       \
    if(expr) { }                                                        \
    else                                                                \
    {                                                                   \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);        \
        debugBreak();                                                   \
    }                                                                   \
}
#else
#define PRIAXE_ASSERT_DEBUG(expr)   // Does jack shit
#endif

#else
#define PRIAXE_ASSERT(expr)
#define PRIAXE_ASSERT_MSG(expr, message)
#define PRIAXE_ASSERT_DEBUG(expr)
#endif