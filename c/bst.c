#include <stdio.h>
#include <math.h>

#include "bst.h"

int main(int argc, char* argv[])
{
    bst T = { .root = NULL };

    bst_node one = { .val = 2 };
    bst_node two = { .val = 10 };
    bst_node three = { .val = 1 };
    bst_node four = { .val = 7 };
    bst_node five = { .val = 5 };
    bst_node six = { .val = 16 };
    bst_node seven = { .val = 9 };
    bst_node eight = { .val = 14 };
    bst_node nine = { .val = 11 };

    bst_insert(&T, &one);
    bst_insert(&T, &two);
    bst_insert(&T, &three);
    bst_insert(&T, &four);
    bst_insert(&T, &five);
    bst_insert(&T, &six);
    bst_insert(&T, &seven);
    bst_insert(&T, &eight);
    bst_insert(&T, &nine);

    inorder_tree_walk(T.root);

    printf("\nSearch: %d", tree_search(&T, 5)->val);
    printf("\nMax: %d", tree_maximum(T.root)->val);
    printf("\nMin: %d", tree_minimum(T.root)->val);
    printf("\n");

    bst_delete(&T, &five);
    inorder_tree_walk(T.root);
}