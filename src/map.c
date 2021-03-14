#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include "map.h"

int
map_create(map_ds **map, int bucket_sz, typecheck_t type)
{    
    int i, rc = ENOMEM;
    
    *map = malloc(sizeof(map_ds));
    if (!*map)
        goto err3;
        
    (*map)->data = malloc(sizeof(list_ds *) * bucket_sz);
    if (!(*map)->data)
        goto err2;

    for (i = 0; i < bucket_sz; i++) {
        rc = list_create(&(*map)->data[i], type);
        if (rc)
            goto err1;
    }

    (*map)->bucket_sz = bucket_sz;
    (*map)->type = type;

    return 0;
err1:
    while (--i >= 0)
        list_destroy((*map)->data[i]);
    free((*map)->data);
err2:
    free(*map);
err3:
    return rc;
}

static
int
map_hash(map_ds *map, char *key)
{
    int  i;
    int  total = 0;

    for (i = 0; i < strlen(key); i++)
        total += key[i];

    return total % map->bucket_sz;
}
    
void
_map_put_int(map_ds *map, char *key, int val)
{
    node_ds  *seek;
    int       bucket = map_hash(map, key);

    if (map->type != INTEGER) {
        fprintf(stderr, "map_error: put value %d mismatches <%s> map\n",
                val, typename[map->type]);
        exit(1);
    }
    
    seek = map->data[bucket]->head;

    while (seek && strcmp(seek->key, key))
        seek = seek->next;

    if (!seek) {
        _list_push_int(map->data[bucket], key, val);
        return;
    }

    seek->val.d = val;
}

void
_map_put_double(map_ds *map, char *key, double val)
{
    node_ds  *seek;
    int       bucket = map_hash(map, key);

    if (map->type != DOUBLE) {
        fprintf(stderr, "map_error: put value %f mismatches <%s> map\n",
                val, typename[map->type]);
        exit(1);
    }
    
    seek = map->data[bucket]->head;

    while (seek && strcmp(seek->key, key))
        seek = seek->next;

    if (!seek) {
        _list_push_double(map->data[bucket], key, val);
        return;
    }

    seek->val.f = val;
}

void
_map_put_string(map_ds *map, char *key, char *val)
{
    node_ds  *seek;
    int       bucket = map_hash(map, key);

    if (map->type != STRING) {
        fprintf(stderr, "map_error: put value %s mismatches <%s> map\n",
                val, typename[map->type]);
        exit(1);
    }

    seek = map->data[bucket]->head;

    while (seek && strcmp(seek->key, key))
        seek = seek->next;

    if (!seek) {
        _list_push_string(map->data[bucket], key, val);
        return;
    }

    seek->val.s = val;
}

value_t
map_get(map_ds *map, char *key)
{
    node_ds  *seek;
    int       bucket = map_hash(map, key);

    seek = map->data[bucket]->head;

    while (seek && strcmp(seek->key, key))
        seek = seek->next;
    
    if (!seek)
        return (value_t)INT_MIN;
    
    return seek->val;
}

void
map_destroy(map_ds *map)
{
    int i;

    for (i = 0; i < map->bucket_sz; i++)
        list_destroy(map->data[i]);

    free(map->data);
    free(map);
}
