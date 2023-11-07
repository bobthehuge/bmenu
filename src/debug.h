#ifndef DEBUG_H 
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define __DBGPRINT(lvl, fmt, ...)                   \
    do                                              \
    {                                               \
        char* _fmt = malloc(strlen((fmt))+12);      \
        strcat(_fmt, "[%s] '%s': ");                \
        strcat(_fmt, (fmt));                        \
        warnx(_fmt, (lvl), __func__, __VA_ARGS__);  \
    }while(0);

#ifndef NOLOG
#define LOGF(fmt, ...) \
    __DBGPRINT("LOG", (fmt), __VA_ARGS__);

#define LOG(str) \
    LOGF("%s", (str));
#else
#define LOG(...)
#define LOGF(...)
#endif /* LOG */

#ifndef NOWARN
#define WARNF(fmt, ...) \
    __DBGPRINT("WARNING", (fmt), __VA_ARGS__);

#define WARN(str) \
    WARNF("%s", (str));
#else
#define WARN(...)
#define WARNF(...)
#endif /* WARN */

#endif /* ! */
