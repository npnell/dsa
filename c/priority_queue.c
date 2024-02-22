#include <stdio.h>
#include <stdlib.h>

#include "priority_queue.h"

int main(int argc, char* argv[])
{
    heap h = { .e = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}, .size = 10 };

    build_max_heap(&h);

    printf("max: %d\n", heap_max(&h));
    printf("extract_max: %d\n", heap_extract_max(&h));
    heap_increase_key(&h, 1, 18);
    heap_insert_key(&h, 11);
    
    for(int i = 0; i < h.size; ++i)
        printf("%d ", h.e[i]);
    printf("\n");
}