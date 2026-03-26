/* date = March 25th 2026 10:14 am */

#ifndef BASE_CORE_H
#define BASE_CORE_H

#include <stdint.h>
#include <stdbool.h>

#if !defined(MIN)
#define MIN(a, b) (a) < (b) ? (a) : (b)
#endif

#if !defined(MAX)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#endif

#if !defined(CLAMP)
#define CLAMP(val, min, max) MIN(MAX(val, min), max)
#endif

#endif //BASE_CORE_H
