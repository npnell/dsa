#ifndef STACK_H
#define STACK_H

#define SIZE 64

typedef struct stack {
    int v[SIZE];
    int top;
} stack;

int empty(const stack *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

int push(stack *s, int x)
{
    if(s->top >= SIZE)
        return -1;
    s->top = s->top + 1;
    s->v[s->top] = x;
}

int pop(stack *s)
{
    if(s->top < 0)
        return -1;
    int x = s->v[s->top];
    s->top = s->top - 1;
    return x;
}

#endif