#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define TOTAL_NODES 16

/*
 * Graph Data Structure
*/

typedef struct gnode {
    int val;
    int visited;
    struct rnode *next;
} gnode;

typedef struct rnode {
    struct rnode *next;
    struct gnode *ref;
} rnode;

typedef struct graph {
    gnode *nodes[TOTAL_NODES];
    int size;
} graph;

/*
 * Stack Operations
*/

typedef struct stack {
    gnode *v[TOTAL_NODES];
    int top;
} stack;

int empty(const stack *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

int push(stack *s, gnode *x)
{
    if(s->top >= TOTAL_NODES)
        return -1;
    s->top = s->top + 1;
    s->v[s->top] = x;
    return 0;
}

gnode* pop(stack *s)
{
    if(s->top < 0)
        return NULL;
    gnode *x = s->v[s->top];
    s->top = s->top - 1;
    return x;
}

/*
 * Queue Operations
*/

typedef struct queue {
    gnode *v[TOTAL_NODES];
    int head;
    int tail;
} queue;

void enqueue(queue *q, gnode *x)
{
    q->v[q->tail] = x;
    if(q->tail == TOTAL_NODES - 1)
        q->tail = 0;
    else q->tail = q->tail + 1;
}

gnode* dequeue(queue *q)
{
    gnode *x = q->v[q->head];
    if(q->head == TOTAL_NODES - 1)
        q->head = 0;
    else q->head = q->head + 1;
    return x;
}

int qempty(queue *q)
{
    if(q->head == q->tail)
        return 1;
    return 0;
}

/*
 * Graph Methods
*/

int add_node(graph *g, gnode *node)
{
    static int n = 0;
    if(n >= TOTAL_NODES) {
        return -1;
    }
    g->nodes[n] = node;
    g->size = g->size + 1;
    n += 1;
    return 0;
}

void add_edge(gnode *node_1, gnode *node_2)
{   
    rnode *new_node = malloc(sizeof(rnode));
    new_node->ref = node_2;
    new_node->next = node_1->next;
    node_1->next = new_node;

    new_node = malloc(sizeof(gnode));
    new_node->ref = node_1;
    new_node->next = node_2->next;
    node_2->next = new_node;
}

void delete_graph(graph *g)
{
    rnode *cur, *prev;
    for(int i = 0; i < g->size; ++i) {
        cur = (g->nodes[i])->next;
        while(cur->next != NULL) {
            prev = cur;
            cur = cur->next;
            free(prev);
        }
        free(cur);
    }
}

/*
 * Graph Traversal
*/

void row_push(stack *s, gnode *cur)
{
    rnode *rcur = cur->next;
    while(rcur != NULL) {
        if(rcur->ref->visited == 1) {
            rcur = rcur->next;
            continue;
        }
        push(s, rcur->ref);
        rcur = rcur->next;
    }
}

void qrow_push(queue *q, gnode *cur)
{
    rnode *rcur = cur->next;
    while(rcur != NULL) {
        if(rcur->ref->visited == 1) {
            rcur = rcur->next;
            continue;
        }
        enqueue(q, rcur->ref);
        rcur = rcur->next;
    }
}

void dfs(gnode *node)
{
    stack s = { .top = -1 };
    gnode *cur;

    push(&s, node);

    while(!empty(&s)) {
        cur = pop(&s);
        cur->visited = 1;
        printf("%c ", cur->val);
        row_push(&s, cur);
    }
}

void bfs(gnode *node)
{
    queue q = { .head = 0, .tail = 0 };
    gnode *cur;

    enqueue(&q, node);

    while(!qempty(&q)) {
        cur = dequeue(&q);
        cur->visited = 1;
        printf("%c ", cur->val);
        qrow_push(&q, cur);
    }
}

#endif