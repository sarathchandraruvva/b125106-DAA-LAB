#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
    return (a>b?a:b);
}
void LCS(char X[],char Y[]){
    int m = strlen(X);
    int n = strlen(Y);
    int **dp = (int**)malloc((m+1)*sizeof(int*));
    for(int i=0;i<i<=m;i++){
        dp[i]=(int*)malloc((n+1)*sizeof(int));
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int length = dp[m][n];
    char *lcs = (char*)malloc(length * sizeof(char));
    lcs[length]='\0';
    int i=m;
    int j=n;
    int index = length - 1;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index]=X[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("Length of lcs = %d\n",length);
    printf("LCS = %s\n",lcs);
    free(lcs);
    for(i=0;i<=m;i++){
        free(dp[i]);
    }
    free(dp);
}
int main(){
    char X[100],Y[100];
    printf("Enter the first string : ");
    scanf("%s",X);
    printf("Enter the second string : ");
    scanf("%s",Y);
    LCS(X,Y);
    return 0;
}