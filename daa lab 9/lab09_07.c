#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    int *a = malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter positive integers:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if (a[i] <= 0 || a[i] > 1073741823)
        {
            printf("Invalid input\n");
            free(a);
            return 1;
        }

        // Make every number even initially.
        if (a[i] % 2 != 0)
        {
            a[i] *= 2;
        }
    }

    int minimum = a[0];
    int maximum = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minimum)
        {
            minimum = a[i];
        }

        if (a[i] > maximum)
        {
            maximum = a[i];
        }
    }

    int bestDeviation = maximum - minimum;

    while (maximum % 2 == 0)
    {
        // Halve the current maximum.
        maximum /= 2;

        // Update the smallest value.
        if (maximum < minimum)
        {
            minimum = maximum;
        }

        // Update the maximum deviation found so far.
        int deviation = maximum - minimum;

        if (deviation < bestDeviation)
        {
            bestDeviation = deviation;
        }

        // Find the new maximum.
        for (int i = 0; i < n; i++)
        {
            if (a[i] == maximum * 2)
            {
                a[i] = maximum;
                break;
            }
        }

        maximum = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] > maximum)
            {
                maximum = a[i];
            }
        }
    }

    printf("Minimum deviation = %d\n", bestDeviation);

    free(a);

    return 0;
}