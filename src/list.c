#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "list.h"

int
list_create(list_t **list)
{
    *list = malloc(sizeof(list_t));
    if (!*list)
        return ENOMEM;

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
    
    return 0;
}

int
_list_push(list_t *list, void *val)
{
    int      rc;
    node_t  *node;

    rc = node_create(&node, NULL, val);
    if (rc)
        return rc;

    list->size++;
    
    if (!list->head) {
        list->head = node;
        list->tail = list->head;
        return 0;
    }

    list->tail->next = node;
    list->tail = list->tail->next;

    return 0;
}

void *
list_pop(list_t *list)
{
    void    *val;
    node_t  *copy;

    if (!list->head)
        return NULL;
 
    val = list->head->val;

    copy = list->head;
    list->head = list->head->next;
    node_destroy(copy);

    list->size--;
    
    return val;
}

void *
list_get(list_t *list, int idx)
{
    int      i = 0;
    node_t  *seek = list->head;
    
    if (idx > list->size - 1)
        return NULL;

    while (i != idx) {
        i++;
        seek = seek->next;
    }

    return seek->val;
}

void
list_destroy(list_t *list)
{
    node_t *copy, *seek = list->head;

    while (seek) {
        copy = seek;
        seek = seek->next;
        node_destroy(copy);
    }
    
    free(list);
}
