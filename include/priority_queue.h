#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "heap.h"

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