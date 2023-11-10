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

void get_tokens(char* buf)
{
    char** tokens = malloc(sizeof(char*));
    size_t token_count = 1;

    char* tok = strtok(buf, " ");
    tokens[token_count-1] = tok;

    while (tok != NULL)
    {
        tok = strtok(NULL, " ");
        token_count++;
        tokens = realloc(tokens, token_count);
        tokens[token_count-1] = tok;
    }

    printf("dummy\n");
}

int main(void)
{
    char __buffer[BUFSIZE];
    char* buffer = __buffer;

    get_input(buffer);

    char* cbuf = malloc(strlen(buffer));
    strcat(cbuf, buffer);

    get_tokens(cbuf);

    free(cbuf);
    return 0;
}
