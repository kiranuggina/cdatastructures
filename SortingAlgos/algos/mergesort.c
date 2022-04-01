#include "sortingalgos.h"

void merge(int a[], const int lb, const int mid, const int ub)
{
        int i = lb, j = mid + 1, k = lb;
        int b[ub];
        while (i <= mid && j <= ub)
        {
                if (a[i] <= a[j])
                {
                        b[k] = a[i];
                        i++;
                }
                else
                {
                        b[k] = a[j];
                        j++;
                }
                k++;
        }
        if (i > mid)
        {
                while (j <= ub)
                {
                        b[k] = a[j], j++, k++;
                }
        }
        else
        {
                while (i <= mid)
                {
                        b[k] = a[i], i++, k++;
                }
        }
        for(k=lb; k<=ub; k++)
            a[k] = b[k];
}

void mergeSort(int a[], int lb, int ub)
{
        if (lb < ub)
        {
                int mid = (lb + ub) / 2;
                mergeSort(a, lb, mid);
                mergeSort(a, mid + 1, ub);
                merge(a, lb, mid, ub);
        }
        return;
}