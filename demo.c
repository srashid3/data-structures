#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int
main(int argc, char **argv)
{
    node_t *node1, *node2;

    node_create(&node1, "foobar", 2000);
    node_create(&node2, "hello", "world");

    printf("Key = %s, Value = %d\n", node1->key, (int)node1->val);
    printf("Key = %s, Value = %s\n", node2->key, (char *)node2->val);

    node_destroy(node1);
    node_destroy(node2);
}
