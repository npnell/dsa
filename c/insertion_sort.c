#include <stdio.h>

int* insertion_sort(int n, int v[])
{
    for(int i = 0; i < n; ++i) {
        int key = v[i];
        int j = i - 1;
        while(v[j] > key && j >= 0) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    return v;
}

void print_array(int n, int v[])
{
    for(int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
}

int main(int argc, char* argv[])
{
    int v[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(v) / sizeof(v[0]);

    insertion_sort(n, v);
    print_array(n, v);
    printf("\n");
}