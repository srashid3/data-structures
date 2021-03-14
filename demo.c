#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "list.h"
#include "stack.h"
#include "map.h"

void
test_node()
{
    node_ds *node1, *node2;

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
    node_ds  *seek;
    list_ds  *list;

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
        printf("%d > ", seek->val.d);
        seek = seek->next;
    }

    printf("\b\b\n");
    
    printf("Index = 1, Value = %d\n", list_get(list, 1)->val.d);

    list_destroy(list);
}

void
test_stack()
{
    int        i;
    stack_ds  *stack;

    printf("[STACK]\n");
    
    stack_create(&stack, 4, INTEGER);

    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);

    stack_pop(stack);
    stack_pop(stack);

    for (i = stack->top; i >= 0; i--)
        printf("%d > ", stack->data[i].d);

    printf("\b\b\n");

    printf("Top = %d\n", stack_peak(stack).d);
    printf("Full = %s\n", stack_is_full(stack) ? "True" : "False");
    printf("Empty = %s\n", stack_is_empty(stack) ? "True" : "False");

    stack_destroy(stack);
}

void
test_map()
{
    map_ds  *map;
    value_t  val;

    printf("[MAP]\n");

    map_create(&map, 4, INTEGER);

    map_put(map, "foobar", 1995);
    map_put(map, "foobar", 2000);
    
    val = map_get(map, "foobar");

    printf("Key = %s, Value = %d\n", "foobar", val.d);

    map_destroy(map);
}

int
main(int argc, char **argv)
{
    test_node();
    test_list();
    test_stack();
    test_map();
}
