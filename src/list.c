#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "list.h"

int
list_create(list_t **list, typecheck_t type)
{
    *list = malloc(sizeof(list_t));
    if (!*list)
        return ENOMEM;

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
    (*list)->type = type;
    
    return 0;
}

int
_list_push_int(list_t *list, int val)
{
    int      rc;
    node_t  *node;

    if (list->type != INTEGER) {
        fprintf(stderr, "list_error: push value %d mismatches <%s> list\n",
                val, typename[list->type]);
        exit(1);
    }
    
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

int
_list_push_double(list_t *list, double val)
{
    int      rc;
    node_t  *node;

    if (list->type != DOUBLE) {
        fprintf(stderr, "list_error: push value %f mismatches <%s> list\n",
                val, typename[list->type]);
        exit(1);
    }
    
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

int
_list_push_string(list_t *list, char *val)
{
    int      rc;
    node_t  *node;

    if (list->type != STRING) {
        fprintf(stderr, "list_error: push value %s mismatches <%s> list\n",
                val, typename[list->type]);
        exit(1);
    }
    
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

void
list_pop(list_t *list)
{
    node_t *copy;

    if (!list->size)
        return;

    copy = list->head;
    list->head = list->head->next;
    node_destroy(copy);

    list->size--;
}

node_t *
list_get(list_t *list, int idx)
{
    int      i = 0;
    node_t  *seek = list->head;
    
    if (idx < 0 || idx > list->size - 1) {
        fprintf(stderr, "list_error: pop index %d out of range\n", idx);
        exit(1);
    }

    while (i++ != idx)
        seek = seek->next;

    return seek;
}

void
list_remove(list_t *list, int idx)
{
    int      i = 0;
    node_t  *prev, *seek = list->head;

    if (idx < 0 || idx > list->size - 1) {
        fprintf(stderr, "list_error: remove index %d out of range\n", idx);
        exit(1);
    }

    while (i++ != idx) {
        prev = seek;
        seek = seek->next;
    }

    prev->next = seek->next;
    node_destroy(seek);
    
    list->size--;
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
