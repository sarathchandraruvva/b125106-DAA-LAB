#include <stdio.h>
#define MAX 50
#define INF 999999.0
int main(){
    int n;
    int i, j, r, l;
    double p[MAX], q[MAX];
    double e[MAX][MAX];
    double w[MAX][MAX];
    int root[MAX][MAX];
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter %d successful search probabilities (p1 to pn):\n", n);
    for (i = 1; i <= n; i++){
        scanf("%lf", &p[i]);
    }
    printf("Enter %d unsuccessful search probabilities (q0 to q%d):\n",n + 1, n);
    for (i = 0; i <= n; i++){
        scanf("%lf", &q[i]);
    }
    /*
       Initialization for empty subtrees

       e[i][i-1] = q[i-1]
       w[i][i-1] = q[i-1]
    */
    for (i = 1; i <= n + 1; i++){
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    /*
       Calculate optimal cost for subtrees
       of increasing length.
    */
    for (l = 1; l <= n; l++){
        for (i = 1; i <= n - l + 1; i++){
            j = i + l - 1;
            e[i][j] = INF;
            /*
               Calculate total probability
            */
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            /*
               Try every key as root
            */
            for (r = i; r <= j; r++){
                double cost;
                cost = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (cost < e[i][j]){
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }
    printf("\nMinimum Expected Search Cost = %.4lf\n",e[1][n]);
    printf("\nRoot of the Optimal BST = k%d\n",root[1][n]);
    /*
       Display root table
    */
    printf("\nRoot Table:\n");
    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            printf("root[%d][%d] = k%d\n",i, j, root[i][j]);
        }
    }
    return 0;
}