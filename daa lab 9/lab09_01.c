#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double value;
    double weight;
    double decay;
    double remaining;
} Item;

int main()
{
    int n;
    double capacity;
    double totalValue = 0.0;
    double time = 0.0;

    printf("Enter number of items and capacity: ");
    scanf("%d %lf", &n, &capacity);

    if (n <= 0 || capacity < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    Item *items = malloc(n * sizeof(Item));

    if (items == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter value, weight and decay rate for item %d: ",
               i + 1);

        scanf("%lf %lf %lf",
              &items[i].value,
              &items[i].weight,
              &items[i].decay);

        if (items[i].weight <= 0 ||
            items[i].value < 0 ||
            items[i].decay < 0)
        {
            printf("Invalid item data\n");
            free(items);
            return 1;
        }

        items[i].remaining = items[i].weight;
    }

    // Repeatedly choose the item with the highest current density.
    while (capacity > 1e-9)
    {
        int best = -1;
        double bestDensity = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (items[i].remaining > 1e-9)
            {
                double density =
                    items[i].value / items[i].weight
                    - items[i].decay * time;

                if (density > bestDensity)
                {
                    bestDensity = density;
                    best = i;
                }
            }
        }

        // No remaining item has positive effective density.
        if (best == -1)
        {
            break;
        }

        // Take either the entire remaining item or available capacity.
        double amount = items[best].remaining;

        if (amount > capacity)
        {
            amount = capacity;
        }

        totalValue += amount * bestDensity;
        items[best].remaining -= amount;
        capacity -= amount;
        time += amount;

        printf("Take %.2f units from item %d\n",
               amount, best + 1);
    }

    printf("Simulated total value = %.4f\n", totalValue);

    free(items);
    return 0;
}