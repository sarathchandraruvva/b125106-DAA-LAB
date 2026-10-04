#include<stdio.h>
#include<stdlib.h>
long long countWays(int coins[],int n,int V){
    long long*dp = (long long*)malloc((V+1)*sizeof(long long));
    dp[0]=1;
    for(int i=0;i<=V;i++){
         for(int amount=coins[i];amount<=V;amount++){
            dp[amount]=dp[amount]+dp[amount-coins[i]];
         }
    }
    long long result = dp[V];
    free(dp);
    return result;
}
int main(){
    int n,V;
    printf("Enter the number of coin denominations : ");
    scanf("%d",&n);
    long long *coins = (long long *)malloc(n*sizeof(long long));
    printf("Enter the coins denominations  : ");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    printf("Enter the target amount : ");
    scanf("%d",&V);
    printf("total number of ways : ",CountWays(coins,n,V));
    free(coins);
    return 0;
}
