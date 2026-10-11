#include <stdio.h>
#include <limits.h>

#define MAX 100

long long weight[MAX];
long long prefix[MAX];
long long dp[MAX][MAX];
int split[MAX][MAX];

// Print the tree structure using the stored optimal splits.
void printTree(int left, int right)
{
    if (left == right)
    {
        printf("%d", left + 1);
        return;
    }

    int middle = split[left][right];

    printf("(");
    printTree(left, middle);
    printf(", ");
    printTree(middle + 1, right);
    printf(")");
}

int main()
{
    int n;

    printf("Enter number of ordered weights: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the weights in order:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &weight[i]);

        if (weight[i] < 0)
        {
            printf("Weights must be non-negative\n");
            return 1;
        }

        // Prefix sums allow fast calculation of interval weights.
        prefix[i] = weight[i];

        if (i > 0)
        {
            prefix[i] += prefix[i - 1];
        }
    }

    // A single leaf requires no internal combination.
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // Process intervals in increasing order of length.
    for (int length = 2; length <= n; length++)
    {
        for (int left = 0; left + length <= n; left++)
        {
            int right = left + length - 1;

            long long intervalWeight = prefix[right];

            if (left > 0)
            {
                intervalWeight -= prefix[left - 1];
            }

            dp[left][right] = LLONG_MAX;

            // Try every possible split of this interval.
            for (int k = left; k < right; k++)
            {
                long long cost =
                    dp[left][k]
                    + dp[k + 1][right]
                    + intervalWeight;

                if (cost < dp[left][right])
                {
                    dp[left][right] = cost;
                    split[left][right] = k;
                }
            }
        }
    }

    printf("Minimum weighted path length = %lld\n",dp[0][n - 1]);
    printf("Optimal alphabetic tree: ");
    printTree(0, n - 1);
    printf("\n");

    return 0;
}