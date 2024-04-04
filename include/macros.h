#ifndef _MACROS_H
#define _MACROS_H

#define UNUSED __attribute__((unused))

#if !defined(__GNUC__) && !defined(__clang__)
#define __attribute__(x)
#endif

#endif
