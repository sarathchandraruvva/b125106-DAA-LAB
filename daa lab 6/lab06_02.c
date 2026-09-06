#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    int n,W,i,w;
    int weight[100],profit[100];
    int dp[101][101];
    printf("Enter the number of items : \n");
    scanf("%d",&n);
    printf("Enter the weights of %d objects : ",n);
    for(i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    printf("Enter the profits :\n");
    for(i=0;i<n;i++){
        scanf("%d",&profit[i]);
    }
    printf("Enter the capacity that bag holds : ");
    scanf("%d",&W);
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }
            else if(weight[i-1]<=W){
                dp[i][w]=max(profit[i-1]+dp[i-1][W-weight[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    printf("the maximum profit earned is %d",dp[n][W]);
    return 0;
}
