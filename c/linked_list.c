#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main(int argc, char* argv[])
{
    linked_list ll = { .head = NULL };

    node one   = { .val = 1 };
    node two   = { .val = 2 };
    node three = { .val = 3 };
    node four  = { .val = 4 };

    list_insert(&ll, &one);
    list_insert(&ll, &two);
    list_insert(&ll, &three);
    list_insert(&ll, &four);

    list_delete(&ll, &three);

    printf("%d ", list_search(&ll, 1)->val);
    printf("%d ", list_search(&ll, 2)->val);
    printf("%d ", list_search(&ll, 4)->val);
}