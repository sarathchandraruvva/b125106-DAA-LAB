#include <stdio.h>
void printSwitches(int a[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int findSwitch(int a[], int n){
    int i, j, valid;
    if (a[n - 1] == 1)
        return n - 1;
    for (i = n - 2; i >= 0; i--){
        if (a[i + 1] == 1){
            valid = 1;
            for (j = i + 2; j < n; j++){
                if (a[j] == 1){
                    valid = 0;
                    break;
                }
            }
            if (valid)
                return i;
        }
    }
    return -1;
}
int main(){
    int n, i;
    int a[100];
    int moves = 0;
    int pos;
    printf("Enter number of switches: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100){
        printf("Invalid input.\n");
        return 0;
    }
    for (i = 0; i < n; i++)
        a[i] = 1;
    printf("\nInitial state: ");
    printSwitches(a, n);
    while (1){
        int allOff = 1;
        for (i = 0; i < n; i++){
            if (a[i] == 1){
                allOff = 0;
                break;
            }
        }
        if (allOff)
            break;
        pos = findSwitch(a, n);
        if (pos == -1){
            printf("No valid move possible.\n");
            break;
        }
        a[pos] = 1 - a[pos];
        moves++;
        printf("Move %d: Toggle switch %d -> ",moves, pos + 1);
        printSwitches(a, n);
    }
    printf("\nMinimum number of moves = %d\n", moves);
    return 0;
}