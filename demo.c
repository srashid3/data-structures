#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int
main(int argc, char **argv)
{
    node_t *node;

    node_create(&node, "foobar", 2000);

    printf("Key = %s, Value = %d\n", node->key, node->val);
    
    node_destroy(node);
}
