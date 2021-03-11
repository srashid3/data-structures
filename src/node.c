#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "node.h"

int
_node_create_int(node_t **node, char *key, int val)
{
    *node = malloc(sizeof(node_t));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val.d = val;
    (*node)->next = NULL;

    return 0;
}

int
_node_create_double(node_t **node, char *key, double val)
{
    *node = malloc(sizeof(node_t));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val.f = val;
    (*node)->next = NULL;

    return 0;
}

int
_node_create_string(node_t **node, char *key, char *val)
{
    *node = malloc(sizeof(node_t));
    if (!*node)
        return ENOMEM;

    (*node)->key = key;
    (*node)->val.s = val;
    (*node)->next = NULL;

    return 0;
}

void
node_destroy(node_t *node)
{
    free(node);
}
