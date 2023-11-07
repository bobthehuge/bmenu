#include <err.h>
#include <stdio.h>

#include "debug.h"

#ifndef BUFSIZE
#define BUFSIZE 128
#endif

void get_input(char* buf)
{
    if (scanf("%s", buf) == EOF)
    {
        errx(1, "%s", __func__);
    }
}

int main(void)
{
    char buffer[BUFSIZE];

    get_input(buffer);

    return 0;
}
