#include<stdio.h>
#include<limits.h>
int main(){
    int n,i,j,k,length;
    int arr[100];
    int dp[100][100];
    int cost;
    printf("Enter N :\n");
    scanf("%d",&n);
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        dp[i][j]=0;
    }
    for(length=2;length<n;length++){
        for(i=1;i<n-length+1;i++){
            j = i + length - 1;
            dp[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                cost = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(cost<dp[i][j]){
                    dp[i][j]=cost;
                }
            }
        }
    }
    printf("Minimum number of scalar multiplications are %d\n",dp[i][n-1]);
    return 0;
}