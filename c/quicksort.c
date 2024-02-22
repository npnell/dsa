#include <stdio.h>

#include "util.h"

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r; ++j) {
        if(A[j] <= x) {
            i = i + 1;
            swap(A, i, j);
        }
    }
    swap(A, i + 1, r);
    return i + 1;
}

void quicksort(int A[], int p, int r)
{
    if(p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main(int argc, char* argv[])
{
    int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(A) / sizeof(A[0]);
    
    quicksort(A, 0, n - 1);

    for(int i = 0; i < n; ++i)
        printf("%d ", A[i]);
    printf("\n");
}