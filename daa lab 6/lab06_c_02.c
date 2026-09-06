#include <stdio.h>

#define MAX 50

void display(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void addition(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiplication(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int isZero(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0)
                return 0;
    return 1;
}

int isSymmetric(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i][j] != A[j][i])
                return 0;
    return 1;
}

void transpose(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    addition(A, B, C, n);
    printf("\nAddition:\n");
    display(C, n);

    multiplication(A, B, C, n);
    printf("\nMultiplication:\n");
    display(C, n);

    printf("\nA is %s a zero matrix.\n",
           isZero(A, n) ? "" : "not");

    printf("A is %s symmetric.\n",
           isSymmetric(A, n) ? "" : "not");

    transpose(A, n);
    printf("\nTranspose of A:\n");
    display(A, n);

    return 0;
}