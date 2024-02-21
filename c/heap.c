#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main(int argc, char* argv[])
{
    heap h = { .e = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}, .size = 10 };

    heap_sort(&h);
    h.size = MAX_HEAP_LENGTH;
    for(int i = 0; i < h.size; ++i)
        printf("%d ", h.e[i]);
    printf("\n");
}