#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <math.h>

#include "util.h"

#define MAX_HEAP_LENGTH 10

typedef struct heap {
    int e[MAX_HEAP_LENGTH];
    int size;
} heap;

int heap_parent(int i)
{
    return floor((i - 1) * 0.5f);
}

int heap_left(int i)
{
    return 2 * i + 1;
}

int heap_right(int i)
{
    return 2 * i + 2;
}

void max_heapify(heap *h, int i)
{
    int l = heap_left(i);
    int r = heap_right(i);
    int max = i;

    if(l <= h->size - 1 && h->e[i] < h->e[l])
        max = l;
    if(r <= h->size - 1 && h->e[max] < h->e[r])
        max = r;
    
    if(max != i) {
        swap(h->e, i, max);
        max_heapify(h, max);
    }
}

void build_max_heap(heap *h)
{
    h->size = MAX_HEAP_LENGTH;
    for(int i = floor(h->size * 0.5) - 1; i >= 0; --i) {
        max_heapify(h, i);
    }
}

void heap_sort(heap *h)
{
    build_max_heap(h);
    for(int i = MAX_HEAP_LENGTH - 1; i >= 1; --i) {
        swap(h->e, i, 0);
        h->size = h->size - 1;
        max_heapify(h, 0);
    }
}

/*
 * Priority Queue Operations
*/

int heap_max(const heap *h)
{
    return h->e[0];
}

int heap_extract_max(heap *h)
{
    if(h->size < 1) {
        fprintf(stderr, "error: heap underflow\n");
        exit(1);
    }
    int max = h->e[0];
    h->e[0] = h->e[h->size - 1];
    h->size = h->size - 1;
    max_heapify(h, 0);
    return max;
}

void heap_increase_key(heap *h, int i, int key)
{
    if(key < h->e[i]) {
        fprintf(stderr, "error: new key is smaller than current key\n");
        exit(1);
    }
    h->e[i] = key;
    while(i > 0 && h->e[heap_parent(i)] < h->e[i]) {
        swap(h->e, i, heap_parent(i));
        i = heap_parent(i);
    }
}

void heap_insert_key(heap* h, int key)
{
    h->size = h->size + 1;
    h->e[h->size - 1] = -1;
    heap_increase_key(h, h->size - 1, key);
}

#endif