#include<stdio.h>
#define MAX 100
typedef struct{
    int i;
    int j;
}point;
int main(){
    int n;
    int i,j;
    point original[MAX],inverted[MAX];
    int totalCoins = 0;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    //to generate upright triangle
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            original[totalCoins].i=i;
            original[totalCoins].j=j;
            totalCoins++;
        }
    }
    //to generate inverted triangle(180 degree rotated)
    for(i=0;i<totalCoins;i++){
        inverted[i].i=-original[i].i;
        inverted[i].j=-original[i].j;
    }
    int maxOverlap = 0;
    int bestdx = 0,bestdy = 0;
    /*Translation range : -(n-1) to 2*(n-1) this is sufficient to check all possible overlaps*/
    for(int dx = -(n-1);dx<=2*(n-1);dx++){
        for(int dy = -(n-1);dy<=2*(n-1);dy++){
            int overlap = 0;
            for(i=0;i<totalCoins;i++){
                for(j=0;j<totalCoins;j++){
                    int translatedI = inverted[j].i;
                    int translatedJ = inverted[j].j;
                    if(original[i].i==translatedI && original[i].j==translatedJ){
                        overlap++;
                        break;
                    }
                }
            }
            if(overlap>maxOverlap){
                maxOverlap = overlap;
                bestdx = dx;
                bestdy = dy;
            }
        }
    }
    int minMoves = totalCoins - maxOverlap;
    printf("Total coins = %d\n",totalCoins);
    printf("Maximum overlap = %d\n",maxOverlap);
    printf("Best translation = (%d,%d)\n",bestdx,bestdy);
    printf("Minimum number of moves = %d",minMoves);
    return 0;
}