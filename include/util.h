#ifndef UTIL_H
#define UTIL_H

void swap(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

#endif