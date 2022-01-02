#include "sortingalgos.h"

void selectionSort(int a[], int n)
{
        printf("Selection Sort : \n");
        int i, j, min = 0;
        for (i = 0; i < n-1; i++)
        {
                min = i;
                for (j = i + 1; j < n; j++)
                {
                        if (a[j] < a[min])
                                min = j;
                        if (min != i)
                        {
                                int temp = a[i];
                                a[i] = a[min];
                                a[min] = temp;
                        }
                }
        }
        display(a, n);
        return;
}