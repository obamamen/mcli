#include <stdio.h>
#include "mcli.h"


int main(void)
{
    if (mcli_initialize() != mcli_ok) { printf("mcli_initialize() failed\n"); return 1; }

    printf(MCLI_FG_CYAN "Hello, World!");

    while (1) {}
    return 0;
}