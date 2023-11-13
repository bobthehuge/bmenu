#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "trees.h"

#ifndef BUFSIZE
#define BUFSIZE 128
#endif

#define PROMPT_TXT "bmenu> "

void get_input(char* prompt, char* buf)
{
    printf("%s", prompt);

    if (scanf("%[^\n]%*c", buf) == EOF)
    {
        ERR(1, "I/O Error");
    }
}

char* substr(char* src, size_t len)
{
    char* dst = malloc(len+1);
    memcpy(dst, src, len);
    dst[len] = '\0';
    return dst;
}

struct Tree* strsplit(char* input)
{
    // init the root whose kids waiting for shift/reduce
    // root->value should always be NULL
    struct Tree* root = init_tree(NULL);

    size_t bow = 0; //Beginning Of Word
    size_t i = 0;

    while (input[i] != '\0')
    {
        while (input[i] != '\0' && input[i] == ' ')
        {
            i++;
        }

        bow = i;

        while (input[i] != '\0' && input[i] != ' ')
        {
            i++;
        }

        if (input[i] == '\0')
            break;

        char* val = substr(input+bow, i-bow);
        struct Tree* elt = init_tree(val);
        tree_shift(root, elt);
    }

    return root;
}

int main(void)
{
    char __buffer[BUFSIZE];
    char* buffer = __buffer;
    get_input(PROMPT_TXT, buffer);

    struct Tree* root = strsplit(buffer);
    /* struct Tree* root = strsplit("-n lie  -go"); */

    for (size_t i = 0; i < root->kcount; ++i)
    {
        LOGX("%s", root->kids[i]->value);
    }

    free_tree(root);
    return 0;
}
