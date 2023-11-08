#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"

#ifndef BUFSIZE
#define BUFSIZE 128
#endif

enum FID
{
    NEW,
    CHG,
    CLS
};

void get_input(char* buf)
{
    if (scanf("%[^\n]%*c", buf) == EOF)
    {
        ERR(1, "I/O Error");
    }
}

int main(void)
{
    char __buffer[BUFSIZE];
    char* buffer = __buffer;

    get_input(buffer);

    char* cbuf = malloc(strlen(buffer));
    strcat(cbuf, buffer);

    /* LOGX("'%s'", strtok(NULL, " ")); */
    /* LOGX("'%s'", strtok(NULL, " ")); */
    /* LOGX("'%s'", strtok(NULL, " ")); */

    cbuf = strtok(cbuf, " ");
    for (size_t i = 0; cbuf != NULL; ++i)
    {
        LOGX("'%s'", cbuf);
        cbuf = strtok(NULL, " ");
    }

    free(cbuf);
    return 0;
}
