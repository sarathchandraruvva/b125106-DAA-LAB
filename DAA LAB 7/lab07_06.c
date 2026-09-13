#include <stdio.h>
typedef struct{
    int birth;
    int death;
} Scientist;
int main(){
    int n, i, j;
    Scientist s[100];
    printf("Enter number of scientists: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100){
        printf("Invalid input.\n");
        return 0;
    }
    printf("Enter birth year and death year:\n");
    for (i = 0; i < n; i++){
        scanf("%d %d", &s[i].birth, &s[i].death);
    }
    int bestYear = 0;
    int maxAlive = 0;
    for (i = 0; i < n; i++){
        for (j = s[i].birth; j <= s[i].death; j++){
            int alive = 0;
            int k;
            for (k = 0; k < n; k++){
                if (s[k].birth <= j && j < s[k].death)
                    alive++;
            }
            if (alive > maxAlive){
                maxAlive = alive;
                bestYear = j;
            }
        }
    }
    printf("\nTime when maximum scientists were alive: %d\n",bestYear);
    printf("Maximum number of scientists alive: %d\n",maxAlive);
    return 0;
}