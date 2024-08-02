#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <math.h>

#include "linked_list.h"

#define M 11
#define A 0.6180339887

typedef struct hash_table {
    linked_list slot[M];
} hash_table;

int h_div(int k)
{
    // division method
    return k % M;
}

int h_mul(int k)
{
    // multiplication method
    return floor(M * fmod(k * A, 1.0));
}

void hash_insert(hash_table* ht, node* x)
{
    list_insert(&((ht->slot)[h_mul(x->val)]), x);
}

int hash_search(const hash_table* ht, int k)
{
    node *n;
    if(n = list_search(&((ht->slot)[h_mul(k)]), k))
        return n->val;
    return -1;
}

void hash_delete(hash_table* ht, node* x)
{
    list_delete(&((ht->slot)[h_mul(x->val)]), x);
}

#endif