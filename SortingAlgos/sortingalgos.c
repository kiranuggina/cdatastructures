#include <stdio.h> 
 
void display(int a[], int n) 
{ 
        for (int i = 0; i < n ; i++) 
                printf("%d\t",a[i]);
        printf("\n"); 
} 
 
void insertionSort(int a[], int n) 
{ 
        printf("Insertion Sort :\n"); 
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
        display(a,n); 
        return; 
} 
 
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

void heapify(int arr[], int n, int i)
{
        // Find largest among root, left child and right child
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
                largest = left;

        if (right < n && arr[right] > arr[largest])
                largest = right;

        // Swap and continue heapifying if root is not largest
        if (largest != i) {
                swap(&arr[i], &arr[largest]);
                heapify(arr, n, largest);
        }
}

void heapSort(int arr[], int n)
{
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);

        // Heap sort
        for (int i = n - 1; i >= 0; i--) {
                swap(&arr[0], &arr[i]);

                // Heapify root element to get highest element at root again
                heapify(arr, i, 0);
        }
}


int main()
{
        int a1[] = { 9,8,7,6,5,4,3,2,1 };
        int a2[] = { 9,8,7,6,5,4,3,2,1 };
        int a3[] = { 9,8,7,6,5,4,3,2,1 };
        int a4[] = { 9,8,7,6,5,4,3,2,1 };
	int a5[] = { 9,8,7,6,5,4,3,2,1 };
        printf("Welcome to sorting Algorithms: \n");
        insertionSort(a1, sizeof(a1) / sizeof(a1[0]));

        selectionSort(a2, sizeof(a2) / sizeof(a2[0]));

        printf("Merge Sort: \n");
        mergeSort(a3, 0, sizeof(a3) / sizeof(a3[0]));
	display(a3, sizeof(a3) / sizeof(a3[0]));

	printf("Quick Sort: \n");
        quickSort(a4, 0, sizeof(a4) / sizeof(a4[0]));
	display(a4, sizeof(a4) / sizeof(a4[0]));

	printf("Heap Sort: \n");
	heapSort(a5, sizeof(a5) / sizeof(a5[0]));
	display(a4, sizeof(a5) / sizeof(a5[0]));
        return 0;
}

