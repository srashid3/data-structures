#ifndef STACK_H
#define STACK_H

#include "type.h"

#define stack_push(stack, val) _Generic((val), \
    int: _stack_push_int, \
    double: _stack_push_double, \
    char *: _stack_push_string)(stack, val)

typedef struct dstack {
    value_t     *data;
    int          size;
    int          top;
    typecheck_t  type;
} dstack_t;

int
stack_create(dstack_t **stack, int size, typecheck_t type);

value_t
stack_peak(dstack_t *stack);

void
_stack_push_int(dstack_t *stack, int val);

void
_stack_push_double(dstack_t *stack, double val);

void
_stack_push_string(dstack_t *stack, char *val);

value_t
stack_pop(dstack_t *stack);

int
stack_is_full(dstack_t *stack);

int
stack_is_empty(dstack_t *stack);

void
stack_destroy(dstack_t *stack);

#endif
