#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 64

typedef struct queue {
    int v[SIZE];
    int head;
    int tail;
} queue;

int enqueue(queue *q, int x)
{
    if(q->head == q->tail && q->head != 0)
        return -1;
    q->v[q->tail] = x;
    if(q->tail == SIZE - 1)
        q->tail = 0;
    else q->tail = q->tail + 1;
}

int dequeue(queue *q)
{
    if(q->head == q->tail && q->head != 0)
        return -1;
    int x = q->v[q->head];
    if(q->head == SIZE - 1)
        q->head = 0;
    else q->head = q->head + 1;
    return x;
}

#endif