#include <stdio.h>

#include "stack.h"

stack s = { .top = -1 };

int main(int argc, char* argv[])
{
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
}