#ifndef TYPE_H
#define TYPE_H

typedef enum {
    INTEGER = 0,
    DOUBLE,
    STRING,
    NUM_TYPES
} typecheck_t;

typedef union {
    int     d;
    double  f;
    char   *s;
} multi_t;

extern char typename[NUM_TYPES][10];

#endif
