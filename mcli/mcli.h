/* ================================== *\
 @file     mcli.h
 @project  mcli
 @author   moosm
 @date     1/12/2026
*\ ================================== */

#ifndef MCLI_MCLI_H
#define MCLI_MCLI_H

// ================================================
// PLATFORM DETECTION
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#   define MCLI_WINDOWS
#elif defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__)
#   define MCLI_UNIX
#else
#   error PLATFORM_NOT_SUPPORTED
#endif

#ifdef MCLI_WINDOWS

#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>

#endif

#include <stdio.h>


///////////////////////////////////////
//             INTERFACE
///////////////////////////////////////


#define MCLI_RESET          "\033[0m"

#define MCLI_FG_RED         "\033[31m"
#define MCLI_FG_GREEN       "\033[32m"
#define MCLI_FG_YELLOW      "\033[33m"
#define MCLI_FG_BLUE        "\033[34m"
#define MCLI_FG_MAGENTA     "\033[35m"
#define MCLI_FG_CYAN        "\033[36m"
#define MCLI_FG_WHITE       "\033[37m"
#define MCLI_FG_DEFAULT     "\033[39m"

#define MCLI_BG_RED         "\033[41m"
#define MCLI_BG_GREEN       "\033[42m"
#define MCLI_BG_YELLOW      "\033[43m"
#define MCLI_BG_BLUE        "\033[44m"
#define MCLI_BG_DEFAULT     "\033[49m"

#define MCLI_BOLD           "\033[1m"
#define MCLI_DIM            "\033[2m"
#define MCLI_UNDERLINE      "\033[4m"
#define MCLI_REVERSE        "\033[7m"

#define MCLI_ATTR_RESET     "\033[22;24;27m"


// ================================================
// CORE TYPES
//

enum mcli_result
{
    mcli_ok = 0,
    mcli_error = 1,
};
typedef enum mcli_result mcli_result_t;




// ================================================
// INITIALIZATION & CLEANUP
//


mcli_result_t mcli_initialize(void);


///////////////////////////////////////
//              SOURCE
///////////////////////////////////////
#if defined(MCLI_SOURCE)

mcli_result_t mcli_initialize(void)
{
#ifdef MCLI_WINDOWS

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return mcli_error;

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode))
        return mcli_error;

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    const WINBOOL r = SetConsoleMode(hOut, mode);
    if ( r != FALSE ) return mcli_ok;
    return mcli_error;

#elifdef MLCI_UNIX

    return mcli_ok;

#endif
}

#endif

#endif //MCLI_MCLI_H