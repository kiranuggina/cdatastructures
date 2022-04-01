#include "sortingalgos.h"

void insertionSort(int a[], int n) 
{ 
        int i, j, temp = 0; 
        for (i = 1; i < n; i++) 
        { 
                temp = a[i]; 
                j = i - 1; 
                while (j >= 0 && a[j] > temp) 
                { 
                        a[j + 1] = a[j]; 
                        j--; 
                } 
                a[j + 1] = temp; 
        } 
        return; 
}