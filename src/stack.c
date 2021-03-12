#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "stack.h"

int
stack_create(dstack_t **stack, int size, typecheck_t type)
{
    *stack = malloc(sizeof(stack_t));
    if (!*stack)
        return ENOMEM;

    (*stack)->data = malloc(sizeof(value_t) * size);
    if (!(*stack)->data) {
        free(*stack);
        return ENOMEM;
    }

    (*stack)->size = size;
    (*stack)->top = -1;
    (*stack)->type = type;

    return 0;
}

value_t
stack_peak(dstack_t *stack)
{
    if (stack_is_empty(stack))
        return (value_t)INT_MIN;

    return stack->data[stack->top];
}

void
_stack_push_int(dstack_t *stack, int val)
{
    if (stack->type != INTEGER) {
        fprintf(stderr, "stack_error: push value %d mismatches <%s> stack\n",
                val, typename[stack->type]);
        exit(1);
    }

    if (stack_is_full(stack))
        return;

    stack->data[++stack->top].d = val;
}

void
_stack_push_double(dstack_t *stack, double val)
{
    if (stack->type != DOUBLE) {
        fprintf(stderr, "stack_error: push value %f mismatches <%s> stack\n",
                val, typename[stack->type]);
        exit(1);
    }

    if (stack_is_full(stack))
        return;

    stack->data[++stack->top].f = val;
}

void
_stack_push_string(dstack_t *stack, char *val)
{
    if (stack->type != STRING) {
        fprintf(stderr, "stack_error: push value %s mismatches <%s> stack\n",
                val, typename[stack->type]);
        exit(1);
    }

    if (stack_is_full(stack))
        return;

    stack->data[++stack->top].s = val;
}

value_t
stack_pop(dstack_t *stack)
{
    if (stack_is_empty(stack))
        return (value_t)INT_MIN;

    return stack->data[stack->top--];
}

int
stack_is_full(dstack_t *stack)
{
    return stack->top >= stack->size - 1;;
}

int
stack_is_empty(dstack_t *stack)
{
    return stack->top < 0;
}

void
stack_destroy(dstack_t *stack)
{
    free(stack->data);
    free(stack);
}
