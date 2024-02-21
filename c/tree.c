#include <stdio.h>

#include "tree.h"

int main(int argc, char* argv[])
{
    tnode one   = { .val = 1 };
    tnode two   = { .val = 2 };
    tnode three = { .val = 3 };
    tnode four  = { .val = 4 };
    tnode five  = { .val = 5 };

    tree T;
    T.root = &one;
    one.left = &two;
    one.right = &three;
    two.left = &four;
    two.right = &five;

    printf("Preorder: ");
    preorder(T.root);
    printf("\nInorder: ");
    inorder(T.root);
    printf("\nPostorder: ");
    postorder(T.root);
}