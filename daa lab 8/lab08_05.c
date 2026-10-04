#include <stdio.h>
int main(){
    int n, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    int dp[n];
    printf("Enter %d positive integers:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &A[i]);
        dp[i] = A[i];
    }
    for (i = 1; i < n; i++){
        for (j = 0; j < i; j++){
            if (A[j] < A[i]){
                if (dp[j] + A[i] > dp[i]){
                    dp[i] = dp[j] + A[i];
                }
            }
        }
    }
    int maxSum = dp[0];
    for (i = 1; i < n; i++){
        if (dp[i] > maxSum){
            maxSum = dp[i];
        }
    }
    printf("Maximum Sum Increasing Subsequence = %d\n", maxSum);
    return 0;
}