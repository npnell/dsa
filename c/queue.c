#include <stdio.h>

#include "queue.h"

int main(int argc, char* argv[])
{
    queue q = { .head = 0, .tail = 0 };
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
}