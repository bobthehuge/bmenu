#ifndef TREES_H
#define TREES_H

#include <stddef.h>

struct Tree
{
    struct Tree** kids;
    size_t kcount;
    char* value;
};

struct Tree* init_tree(char* value);
void free_tree(struct Tree* tree);
void tree_shift(struct Tree* root, struct Tree* elt);

#endif /* ! */
