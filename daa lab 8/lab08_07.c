#include <stdio.h>
#include <limits.h>
int main(){
    int n, i, j;
    printf("Enter length of rod: ");
    scanf("%d", &n);
    int P[n + 1];
    int dp[n + 1];
    int choice[n + 1];
    printf("Enter prices for pieces of length 1 to %d:\n", n);
    for (i = 1; i <= n; i++){
        scanf("%d", &P[i]);
    }
    dp[0] = 0;
    choice[0] = 0;
    for (i = 1; i <= n; i++){
        dp[i] = INT_MIN;
        for (j = 1; j <= i; j++){
            if (P[j] + dp[i - j] > dp[i]){
                dp[i] = P[j] + dp[i - j];
                choice[i] = j;
            }
        }
    }
    printf("\nMaximum Revenue = %d\n", dp[n]);
    printf("Optimal Piece Lengths: ");
    i = n;
    while (i > 0){
        printf("%d ", choice[i]);
        i = i - choice[i];
    }
    printf("\n");
    return 0;
}