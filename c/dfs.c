#include <stdio.h>
#include <math.h>

#include "graph.h"

int main(int argc, char* argv[])
{
    graph Gr = { .size = 0 };
    gnode A = { .val = 'A', .next = NULL, .visited = 0 };
    gnode B = { .val = 'B', .next = NULL, .visited = 0 };
    gnode C = { .val = 'C', .next = NULL, .visited = 0 };
    gnode D = { .val = 'D', .next = NULL, .visited = 0 };
    gnode E = { .val = 'E', .next = NULL, .visited = 0 };
    gnode F = { .val = 'F', .next = NULL, .visited = 0 };
    gnode G = { .val = 'G', .next = NULL, .visited = 0 };
    gnode H = { .val = 'H', .next = NULL, .visited = 0 };
    gnode I = { .val = 'I', .next = NULL, .visited = 0 };

    add_node(&Gr, &A);
    add_node(&Gr, &B);
    add_node(&Gr, &C);
    add_node(&Gr, &D);
    add_node(&Gr, &E);
    add_node(&Gr, &F);
    add_node(&Gr, &G);
    add_node(&Gr, &H);
    add_node(&Gr, &I);

    add_edge(&A, &B);
    add_edge(&A, &G);
    add_edge(&B, &C);
    add_edge(&B, &D);
    add_edge(&B, &E);
    add_edge(&E, &F);
    add_edge(&G, &H);
    add_edge(&H, &I);

    dfs(&A);

    delete_graph(&Gr);
}