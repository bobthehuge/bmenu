#include <stdlib.h>

#include "debug.h"
#include "trees.h"

struct Tree* init_tree(char* value)
{
    struct Tree* tree = malloc(sizeof(struct Tree));

    tree->kids = NULL;
    tree->kcount = 0;
    tree->value = value;

    return tree;
}

void free_tree(struct Tree* tree)
{
    for (size_t i = 0; i < tree->kcount; ++i)
    {
        free_tree(tree->kids[i]);
    }

    free(tree->kids);
    free(tree->value);
    free(tree);
}

// expands `root`'s kids and puts `elt` at the end of it
void tree_shift(struct Tree* root, struct Tree* elt)
{
    root->kcount++;

    if (root->kids == NULL)
    {
        root->kids = malloc(sizeof(struct Tree*));
    }
    else
    {
        root->kids = realloc(root->kids, root->kcount*sizeof(struct Tree*));
    }

    root->kids[root->kcount-1] = elt;
}
