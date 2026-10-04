#include<stdio.h>
#include<stdlib.h>
#define INF 999999

int min(int a,int b){
     return (a>b)?b:a;
}
int minimumCoins(int coins[],int n,int V){
    int *dp = (int *)malloc((V+1)*sizeof(int));
    dp[0]=0;
    for(int i=1;i<=V;i++){
        dp[i]=INF;
    }
    for(int amount=1;amount<=V;amount++){
        for(int j=0;j<n;j++){
            if(coins[j]<=amount && dp[amount-coins[j]]!=INF){
                dp[amount]=min(dp[amount],dp[amount-coins[j]]+1);
            }
        }
    }
    int result = (dp[V]==INF)?-1:dp[V];
    free(dp);
    return result;
} 
int main(){
    int n,V;
    printf("Enter the number of coin denominations : ");
    scanf("%d",&n);
    int *coins = (int*)malloc(n*sizeof(int));
    printf("Enter the coins denominations  : ");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    printf("Enter the target amount : ");
    scanf("%d",&V);
    printf("The minimum number of coins = %d\n",minimumCoins(coins,n,V));
    free(coins);
    return 0;
}