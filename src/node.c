#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "node.h"

int
_node_create(node_t **node, char *key, void *val)
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
