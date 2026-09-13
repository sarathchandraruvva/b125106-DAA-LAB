#include <stdio.h>
#include <limits.h>
#define MAX 100
int m[MAX][MAX],s[MAX][MAX],p[MAX];
void printOptimalOrder(int i, int j){
    if (i == j){
        printf("A%d", i);
        return;
    }
    printf("(");
    printOptimalOrder(i, s[i][j]);
    printOptimalOrder(s[i][j] + 1, j);
    printf(")");
}
int main(){
    int n, i, j, k, length,cost;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    if (n <= 0 || n >= MAX){
        printf("Invalid input.\n");
        return 0;
    }
    printf("Enter %d dimensions:\n", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    for (length = 2; length <= n; length++){
        for (i = 1; i <= n - length + 1; i++){
            j = i + length - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++){
                cost = m[i][k]+ m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nMinimum number of scalar multiplications = %d\n", m[1][n]);
    printf("Optimal parenthesization = ");
    printOptimalOrder(1, n);
    printf("\n");
    return 0;
}