#ifndef NODE_H
#define NODE_H

#include "type.h"

#define node_create(node, key, val) _Generic((val), \
    int: _node_create_int, \
    double: _node_create_double, \
    char *: _node_create_string)(node, key, val)

typedef struct node {
    char         *key;
    multi_t       val;
    struct node  *next;
} node_t;

int
_node_create_int(node_t **node, char *key, int val);

int
_node_create_double(node_t **node, char *key, double val);

int
_node_create_string(node_t **node, char *key, char *val);

void
node_destroy(node_t *node);

#endif
