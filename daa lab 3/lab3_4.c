#include<stdio.h>
#define MAX 64
void ADD(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void SUBTRACT(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]=A[i][j] - B[i][j];
        }
    }
}
void strassen(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n){
    if(n==1){
        C[0][0]=A[0][0]*B[0][0];
        return ;
    }
    int k = n/2;
    int A11[MAX][MAX]={0},A12[MAX][MAX]={0};
    int A21[MAX][MAX]={0},A22[MAX][MAX]={0};
    int B11[MAX][MAX]={0},B12[MAX][MAX]={0};
    int B21[MAX][MAX]={0},B22[MAX][MAX]={0};
    int P1[MAX][MAX]={0},P2[MAX][MAX]={0};
    int P3[MAX][MAX]={0},P4[MAX][MAX]={0};
    int P5[MAX][MAX]={0},P6[MAX][MAX]={0};
    int P7[MAX][MAX]={0};
    int X[MAX][MAX]={0},Y[MAX][MAX]={0};
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    }
        SUBTRACT(B12,B22,Y,k);
        strassen(A11,Y,P1,k);

        ADD(A11,A12,X,k);
        strassen(X,B22,P2,k);

        ADD(A21,A22,X,k);
        strassen(X,B11,P3,k);

        SUBTRACT(B21,B11,Y,k);
        strassen(A22,Y,P4,k);

        ADD(A11,A22,X,k);
        ADD(B11,B22,Y,k);
        strassen(X,Y,P5,k);

        SUBTRACT(A12,A22,X,k);
        ADD(B21,B22,Y,k);
        strassen(X,Y,P6,k);

        SUBTRACT(A11,A21,X,k);
        ADD(B11,B12,Y,k);
        strassen(X,Y,P7,k);

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                C[i][j]=P5[i][j]+P4[i][j]-P2[i][j]+P6[i][j];
                C[i][j+k]=P1[i][j]+P2[i][j];
                C[i+k][j]=P3[i][j]+P4[i][j];
                C[i+k][j+k]=P5[i][j]+P1[i][j]-P3[i][j]-P7[i][j];
            }
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
        printf("Enter n as a power of 2 and n <= %d.\n",MAX);
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

    strassen(A,B,C,n);

    printf("Result matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}

