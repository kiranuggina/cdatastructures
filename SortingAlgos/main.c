#include "sortingalgos.h"
 
void display(int a[], int n) 
{ 
        for (int i = 0; i < n ; i++) 
                printf("%d\t",a[i]);
        printf("\n"); 
} 

int main()
{
        int a1[] = { 9,8,7,6,5,4,3,2,1 };
        int a2[] = { 9,8,7,6,5,4,3,2,1 };
        int a3[] = { 9,8,7,6,5,4,3,2,1 };
        int a4[] = { 9,8,7,6,5,4,3,2,1 };
	int a5[] = { 9,8,7,6,5,4,3,2,1 };
        printf("Welcome to sorting Algorithms: \n");
        
        printf("Insertion Sort :\n");
        insertionSort(a1, sizeof(a1) / sizeof(a1[0]));
        display(a1,sizeof(a1) / sizeof(a1[0])); 

        printf("Selection Sort : \n");
        selectionSort(a2, sizeof(a2) / sizeof(a2[0]));
        display(a2,sizeof(a2) / sizeof(a2[0]));

        printf("Merge Sort: \n");
        mergeSort(a3, 0, (sizeof(a3) / sizeof(a3[0])) - 1);
	display(a3, sizeof(a3) / sizeof(a3[0]));

	printf("Quick Sort: \n");
        quickSort(a4, 0, (sizeof(a4) / sizeof(a4[0])) - 1);
	display(a4, sizeof(a4) / sizeof(a4[0]));

	printf("Heap Sort: \n");
	heapSort(a5, sizeof(a5) / sizeof(a5[0]));
	display(a5, sizeof(a5) / sizeof(a5[0]));
        return 0;
}

