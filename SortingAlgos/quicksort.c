#include "sortingalgos.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], const int lb, const int ub)
{
    int pivot = a[lb];
    int start = lb, end = ub;
    while(start < end)
    {
        while(a[start] <= pivot) {
            start++;
        }
        while(a[end] > pivot) {
            end--;
        }
        if(start < end)
            swap(&a[start], &a[end]);
    }
    swap(&a[lb], &a[end]);
    return end;
}

void quickSort(int a[], int lb, int ub)
{
        if (lb < ub)
        {
                int pi = partition(a,lb, ub);
                quickSort(a, lb, pi - 1);
                quickSort(a, pi + 1, ub);
        }
        return;
}