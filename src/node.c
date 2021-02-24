#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "node.h"

int
node_create(node_t **node, char *key, int val)
{  
    *node = malloc(sizeof(node_t));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val = val;
    (*node)->next = NULL;

    return 0;
}

void
node_destroy(node_t *node)
{
    free(node);
}
