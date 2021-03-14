#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "node.h"

int
_node_create_int(node_ds **node, char *key, int val)
{
    *node = malloc(sizeof(node_ds));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val.d = val;
    (*node)->next = NULL;

    return 0;
}

int
_node_create_double(node_ds **node, char *key, double val)
{
    *node = malloc(sizeof(node_ds));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val.f = val;
    (*node)->next = NULL;

    return 0;
}

int
_node_create_string(node_ds **node, char *key, char *val)
{
    *node = malloc(sizeof(node_ds));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val.s = val;
    (*node)->next = NULL;

    return 0;
}

void
node_destroy(node_ds *node)
{
    free(node);
}
