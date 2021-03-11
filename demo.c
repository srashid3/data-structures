#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "list.h"

void
test_node()
{
    node_t *node1, *node2;

    printf("[NODE]\n");
    
    node_create(&node1, "foobar", 2000);
    node_create(&node2, "hello", "world");

    printf("Key = %s, Value = %d\n", node1->key, node1->val.d);
    printf("Key = %s, Value = %s\n", node2->key, node2->val.s);

    node_destroy(node1);
    node_destroy(node2);
}

void
test_list()
{
    node_t  *seek;
    list_t  *list;

    printf("[LIST]\n");

    list_create(&list, INTEGER);

    list_push(list, 1);
    list_push(list, 2);
    list_push(list, 3);
    list_push(list, 4);
    list_push(list, 5);

    list_pop(list);
    list_remove(list, 1);

    printf("Size = %d\n", list->size);

    seek = list->head;
    while (seek) {
        printf("> %d\n", seek->val.d);
        seek = seek->next;
    }

    printf("Index = 1, Value = %d\n", list_get(list, 1)->val.d);

    list_destroy(list);
}

int
main(int argc, char **argv)
{
    test_node();
    test_list();
}
