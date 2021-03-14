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
} stack_ds;

int
stack_create(stack_ds **stack, int size, typecheck_t type);

value_t
stack_peak(stack_ds *stack);

void
_stack_push_int(stack_ds *stack, int val);

void
_stack_push_double(stack_ds *stack, double val);

void
_stack_push_string(stack_ds *stack, char *val);

value_t
stack_pop(stack_ds *stack);

int
stack_is_full(stack_ds *stack);

int
stack_is_empty(stack_ds *stack);

void
stack_destroy(stack_ds *stack);

#endif
