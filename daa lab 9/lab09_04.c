#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

long long heap[MAX + 1];
int heapSize = 0;

// Insert a length into the min-heap.
void insert(long long value)
{
    int i = ++heapSize;

    while (i > 1 && heap[i / 2] > value)
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i] = value;
}

// Remove the smallest stick length.
long long removeMin(void)
{
    long long minimum = heap[1];
    long long last = heap[heapSize--];

    int i = 1;

    while (2 * i <= heapSize)
    {
        int child = 2 * i;

        if (child + 1 <= heapSize &&
            heap[child + 1] < heap[child])
        {
            child++;
        }

        if (last <= heap[child])
        {
            break;
        }

        heap[i] = heap[child];
        i = child;
    }

    if (heapSize > 0)
    {
        heap[i] = last;
    }

    return minimum;
}

int main( )
{
    int n;
    long long totalCost = 0;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of sticks\n");
        return 1;
    }

    printf("Enter stick lengths:\n");

    for (int i = 0; i < n; i++)
    {
        long long length;
        scanf("%lld", &length);

        if (length <= 0)
        {
            printf("Invalid stick length\n");
            return 1;
        }

        insert(length);
    }

    // Repeatedly connect the two shortest sticks.
    while (heapSize > 1)
    {
        long long first = removeMin();
        long long second = removeMin();

        long long combined = first + second;

        totalCost += combined;

        // The combined stick participates in later connections.
        insert(combined);

        printf("Connected %lld and %lld; cost = %lld\n",
               first, second, combined);
    }

    printf("Minimum total cost = %lld\n", totalCost);

    return 0;
}