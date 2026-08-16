#include <stdio.h>

typedef struct
{
    int min;
    int max;
} Result;

Result findMinMax(int a[], int low, int high)
{
    Result r, left, right;

    if(low == high)
    {
        r.min = r.max = a[low];
        return r;
    }

    if(high == low + 1)
    {
        if(a[low] < a[high])
        {
            r.min = a[low];
            r.max = a[high];
        }
        else
        {
            r.min = a[high];
            r.max = a[low];
        }
        return r;
    }

    int mid = (low + high) / 2;

    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);

    r.min = (left.min < right.min) ? left.min : right.min;
    r.max = (left.max > right.max) ? left.max : right.max;

    return r;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Result r = findMinMax(a, 0, n - 1);

    printf("Minimum = %d\n", r.min);
    printf("Maximum = %d\n", r.max);

    return 0;
}