#include <stdio.h>
#include <stdlib.h>

// Compare two integers for ascending order.
int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main()
{
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    if (n == 0)
    {
        printf("Minimum meeting rooms = 0\n");
        return 0;
    }

    int *start = malloc(n * sizeof(int));
    int *end = malloc(n * sizeof(int));

    if (start == NULL || end == NULL)
    {
        printf("Memory allocation failed\n");
        free(start);
        free(end);
        return 1;
    }

    printf("Enter start and end times of each meeting:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &start[i], &end[i]);

        if (start[i] > end[i])
        {
            printf("Invalid meeting interval\n");
            free(start);
            free(end);
            return 1;
        }
    }

    // Sort starting and ending times independently.
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0;
    int j = 0;
    int currentRooms = 0;
    int maximumRooms = 0;

    while (i < n)
    {
        // A meeting starts before the earliest meeting ends.
        if (j == n || start[i] < end[j])
        {
            currentRooms++;

            if (currentRooms > maximumRooms)
            {
                maximumRooms = currentRooms;
            }

            i++;
        }
        else
        {
            // A room becomes free at this ending time.
            currentRooms--;
            j++;
        }
    }

    printf("Minimum meeting rooms = %d\n", maximumRooms);

    free(start);
    free(end);

    return 0;
}