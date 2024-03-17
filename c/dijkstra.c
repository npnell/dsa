#include <stdio.h>

#define N 5
#define INT_MAX 2147483647

typedef struct node {
    char label;
    int visited;
    int w[N];
} node;

int min_dist_node(node* G, int d[])
{
    int min = INT_MAX;
    int min_i = -1;
    for(int i = 0; i < N; ++i) {
        if(G[i].visited == 0 && d[i] < min) {
            min = d[i];
            min_i = i;
        }
    }
    return min_i;
}

int dist(node* G, int cur, int trg)
{
    return G[cur].w[trg];
}

void dijkstra(node *G, int d[])
{
    for(int i = 0; i < N; ++i) {
        d[i] = INT_MAX;
    }
    int cur = 0;
    G[cur].visited = 1;
    d[cur] = 0;
    int rem = N - 1;

    while(rem) {
        for(int i = 0; i < N; ++i) {
            if(G[i].visited != 1) {
                int dist_to_i = d[cur] + dist(G, cur, i);
                if(dist_to_i >= 0 && dist_to_i < d[i])
                    d[i] = dist_to_i;
            }
        }
        cur = min_dist_node(G, d);
        G[cur].visited = 1;
        rem = rem - 1;
    }
}

int main(int argc, char* argv[])
{
    int d[N];
    node G[] = {
        { .label = 'A', .visited = 0, .w = {0, 4, 2, INT_MAX, INT_MAX} },
        { .label = 'B', .visited = 0, .w = {INT_MAX, 0, 3, 2, 3} },
        { .label = 'C', .visited = 0, .w = {INT_MAX, 1, 0, 4, 5} },
        { .label = 'D', .visited = 0, .w = {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX} },
        { .label = 'E', .visited = 0, .w = {INT_MAX, INT_MAX, INT_MAX, 1, 0} }
    };

    dijkstra(G, d);

    for(int i = 0; i < N; ++i) {
        printf("%d ", d[i]);
    }
    printf("\n");
}