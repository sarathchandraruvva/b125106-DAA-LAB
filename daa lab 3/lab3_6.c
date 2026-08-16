#include <stdio.h>
void selectionSort(int arr[], int n,int* comparisions)
{
    int i, j;
    int minIndex;
    int temp;
    *comparisions = 0;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;    
        /* Find the smallest element */
        for (j = i + 1; j < n; j++)
        {
            (*comparisions)++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        /* Exchange arr[i] and arr[minIndex] */
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int n, i;
    int comparisions;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n,&comparisions);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n No of comparisions = %d\n",comparisions);

    return 0;
}