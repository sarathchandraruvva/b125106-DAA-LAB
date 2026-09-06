#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    char X[100],Y[100];
    int dp[101][101];
    int m,n,i,j;
    char lcs[101];
    int index;
    printf("Enter the first string : ");
    scanf("%s",X);
    printf("Enter the second string : ");
    scanf("%s",Y);
    m = strlen(X);
    n = strlen(Y);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("The length of LCS = %d\n",dp[m][n]);
    index = dp[m][n];
    lcs[index]='\0';
    i=m;
    j=n;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index-1]=X[i-1];
            index--;
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("LCS = %s\n",lcs);
    return 0;
}