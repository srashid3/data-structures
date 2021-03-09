#ifndef NODE_H
#define NODE_H

#define node_create(node, key, val) _node_create(node, key, (void *)val)

typedef struct node {
    char         *key;
    void         *val;
    struct node  *next;
} node_t;

int
_node_create(node_t **node, char *key, void *val);

void
node_destroy(node_t *node);

#endif
