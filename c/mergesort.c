#include <stdio.h>
#include <math.h>

void merge(int A[], int p, int q, int r)
{
    int L[q - p + 2];
    int R[r - q + 1];

    L[q - p + 1] = INFINITY;
    R[r - q] = INFINITY;

    for(int i = 0; i < q - p + 1; ++i)
        L[i] = A[i + p];
    for(int i = 0; i < r - q; ++i)
        R[i] = A[i + q + 1];
    
    int i = 0;
    int j = 0;
    for(int k = p; k < r + 1; ++k) {
        if(L[i] < R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergesort(int A[], int p, int r)
{
    if(p < r) {
        int q = floor((p + r) * 0.5f);
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main(int argc, char* argv[])
{
    int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(A) / sizeof(A[0]);
    
    mergesort(A, 0, n - 1);

    for(int i = 0; i < n; ++i)
        printf("%d ", A[i]);
    printf("\n");
}