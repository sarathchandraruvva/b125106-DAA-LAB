#include <stdio.h>

#define MAX 64

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void sub(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int k=n/2;

    int A1[MAX][MAX]={0},A2[MAX][MAX]={0};
    int B1[MAX][MAX]={0},B2[MAX][MAX]={0};
    int X[MAX][MAX]={0},Y[MAX][MAX]={0};
    int P[MAX][MAX]={0},Q[MAX][MAX]={0};
    int C1[MAX][MAX]={0},C2[MAX][MAX]={0};

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
        {
            A1[i][j]=A[i][j];
            A2[i][j]=A[i][j+k];
            B1[i][j]=B[i][j];
            B2[i][j]=B[i][j+k];
        }

    add(A1,A2,X,k);
    add(B1,B2,Y,k);
    multiply(X,Y,P,k);

    sub(A1,A2,X,k);
    sub(B1,B2,Y,k);
    multiply(X,Y,Q,k);

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
    {
        C1[i][j]=(P[i][j]+Q[i][j])/2;
        C2[i][j]=(P[i][j]-Q[i][j])/2;

        C[i][j]=C1[i][j];
        C[i][j+k]=C2[i][j];
        C[i+k][j]=C2[i][j];
        C[i+k][j+k]=C1[i][j];
    }
}

int main()
{
    int n;
    int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];

    printf("Enter matrix size: ");
    scanf("%d",&n);

    if(n>MAX || (n&(n-1)))
    {
        printf("n must be a power of 2 and <= %d\n",MAX);
        return 1;
    }

    printf("Enter first matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter second matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    multiply(A,B,C,n);

    printf("Result matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}