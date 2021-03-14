#ifndef MAP_H
#define MAP_H

#include "list.h"
#include "type.h"

#define map_put(map, key, val) _Generic((val),   \
    int: _map_put_int, \
    double: _map_put_double, \
    char *: _map_put_string)(map, key, val)

typedef struct {
    list_ds    **data;
    int          bucket_sz;
    typecheck_t  type;
} map_ds;

int
map_create(map_ds **map, int bucket_sz, typecheck_t type);

void
_map_put_int(map_ds *map, char *key, int val);

void
_map_put_double(map_ds *map, char *key, double val);

void
_map_put_string(map_ds *map, char *key, char *val);

value_t
map_get(map_ds *map, char *key);

void
map_destroy(map_ds *map);

#endif
