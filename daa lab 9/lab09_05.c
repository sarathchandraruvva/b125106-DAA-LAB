#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter number of children: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    int *rating = malloc(n * sizeof(int));
    long long *candy = malloc(n * sizeof(long long));

    if (rating == NULL || candy == NULL)
    {
        printf("Memory allocation failed\n");
        free(rating);
        free(candy);
        return 1;
    }

    printf("Enter children's ratings:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rating[i]);

        // Every child must receive at least one candy.
        candy[i] = 1;
    }

    // Left-to-right pass:
    // A child with a higher rating than the left neighbour
    // must receive more candies than that neighbour.
    for (int i = 1; i < n; i++)
    {
        if (rating[i] > rating[i - 1])
        {
            candy[i] = candy[i - 1] + 1;
        }
    }

    // Right-to-left pass:
    // Correct cases where a child needs more candies
    // than the right neighbour.
    for (int i = n - 2; i >= 0; i--)
    {
        if (rating[i] > rating[i + 1] &&
            candy[i] <= candy[i + 1])
        {
            candy[i] = candy[i + 1] + 1;
        }
    }

    long long total = 0;

    printf("Candies given to each child:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", candy[i]);
        total += candy[i];
    }

    printf("\nMinimum total candies = %lld\n", total);

    free(rating);
    free(candy);

    return 0;
}