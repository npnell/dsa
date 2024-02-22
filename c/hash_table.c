#include <stdio.h>
#include <math.h>

#include "hash_table.h"

int main(int argc, char* argv[])
{
    hash_table ht;

    for(int i = 0; i < M; ++i)
        ht.slot[i].head = NULL;

    node one   = { .val = 1 };
    node two   = { .val = 2 };
    node three = { .val = 3 };
    node four  = { .val = 4 };
    node five  = { .val = 5 };
    node six   = { .val = 6 };
    node seven = { .val = 7 };

    hash_insert(&ht, &one);
    hash_insert(&ht, &two);
    hash_insert(&ht, &three);
    hash_insert(&ht, &four);
    hash_insert(&ht, &five);
    hash_insert(&ht, &six);
    hash_insert(&ht, &seven);

    hash_delete(&ht, &five);

    printf("%d ", hash_search(&ht, 1));
    printf("%d ", hash_search(&ht, 2));
    printf("%d ", hash_search(&ht, 3));
    printf("%d ", hash_search(&ht, 4));
    printf("%d ", hash_search(&ht, 5));
    printf("%d ", hash_search(&ht, 6));
    printf("%d ", hash_search(&ht, 7));
}