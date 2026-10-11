#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int distance;
    int fuel;
} Station;

// Sort stations by distance from the starting point.
int compareStations(const void *a, const void *b)
{
    const Station *x = a;
    const Station *y = b;

    return (x->distance > y->distance)
         - (x->distance < y->distance);
}

// Insert a fuel amount into a max heap.
void insertMax(int heap[], int *size, int fuel)
{
    int i = ++(*size);

    while (i > 1 && heap[i / 2] < fuel)
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i] = fuel;
}

// Remove the largest available fuel amount.
int removeMax(int heap[], int *size)
{
    int result = heap[1];
    int last = heap[(*size)--];
    int i = 1;

    while (2 * i <= *size)
    {
        int child = 2 * i;

        if (child + 1 <= *size &&
            heap[child + 1] > heap[child])
        {
            child++;
        }

        if (last >= heap[child])
        {
            break;
        }

        heap[i] = heap[child];
        i = child;
    }

    if (*size > 0)
    {
        heap[i] = last;
    }

    return result;
}

int main()
{
    int n, target, initialFuel;

    printf("Enter number of stations, target distance, "
           "and initial fuel: ");
    scanf("%d %d %d", &n, &target, &initialFuel);

    if (n < 0 || target < 0 || initialFuel < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    Station *stations = malloc(n * sizeof(Station));
    int *heap = malloc((n + 1) * sizeof(int));

    if ((n > 0) && (stations == NULL || heap == NULL))
    {
        printf("Memory allocation failed\n");
        free(stations);
        free(heap);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter station distance and fuel: ");
        scanf("%d %d",
              &stations[i].distance,
              &stations[i].fuel);
    }

    qsort(stations, n, sizeof(Station), compareStations);

    int position = 0;
    int heapSize = 0;
    int stops = 0;
    long long reach = initialFuel;

    // Refuel only when the current reach is insufficient.
    while (reach < target)
    {
        // Add all stations reachable with current fuel.
        while (position < n &&
               stations[position].distance <= reach)
        {
            insertMax(heap, &heapSize,
                      stations[position].fuel);
            position++;
        }

        // No reachable station can provide more fuel.
        if (heapSize == 0)
        {
            printf("Target cannot be reached\n");
            free(stations);
            free(heap);
            return 0;
        }

        // Greedily select the largest available fuel amount.
        reach += removeMax(heap, &heapSize);
        stops++;
    }

    printf("Minimum refuelling stops = %d\n", stops);

    free(stations);
    free(heap);

    return 0;
}