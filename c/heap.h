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

#endif