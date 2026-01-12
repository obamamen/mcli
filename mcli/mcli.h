/* ================================== *\
 @file     mcli.h
 @project  mcli
 @author   moosm
 @date     1/12/2026
*\ ================================== */

#ifndef MCLI_MCLI_H
#define MCLI_MCLI_H
#include <stdio.h>

void test();

#if defined(MCLI_SOURCE)

void test()
{
    printf("Hello, World!\n");
}

#endif

#endif //MCLI_MCLI_H