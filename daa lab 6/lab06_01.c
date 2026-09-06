#include<stdio.h>
int main(){
    int n,i;
    int dp[100];
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    if(n==0){
        printf("Fibonacci number = 0");
        return 0;
    }
    dp[0]=0;
    dp[1]=1;
    for(i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    printf("Fibonacci number = %d",dp[n]);
    return 0;
}