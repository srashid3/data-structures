#ifndef NODE_H
#define NODE_H

typedef struct node {
    char         *key;
    int           val;
    struct node  *next;
} node_t;

int
node_create(node_t **node, char *key, int val);

void
node_destroy(node_t *node);

#endif
