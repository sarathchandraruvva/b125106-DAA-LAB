#include <stdio.h>
int main(){
    int n, i;
    int target, newTarget;
    printf("Enter number of hiding spots: ");
    scanf("%d", &n);
    if (n <= 1){
        printf("Invalid input. n must be greater than 1.\n");
        return 0;
    }
    printf("\nEnter initial target position (1 to %d): ", n);
    scanf("%d", &target);
    if (target < 1 || target > n){
        printf("Invalid target position.\n");
        return 0;
    }
    printf("\nShooter's strategy:\n");
    for (i = 1; i <= n; i++){
        printf("Shot at position %d\n", i);
        if (target == i){
            printf("\nTarget HIT at position %d!\n", i);
            return 0;
        }
        if (target == 1)
            newTarget = 2;
        else if (target == n)
            newTarget = n - 1;
        else{
            newTarget = target + 1;
        }
        target = newTarget;
    }
    for (i = n - 1; i >= 1; i--){
        printf("Shot at position %d\n", i);
        if (target == i){
            printf("\nTarget HIT at position %d!\n", i);
            return 0;
        }
        if (target == 1)
            newTarget = 2;
        else if (target == n)
            newTarget = n - 1;
        else
            newTarget = target - 1;
        target = newTarget;
    }
    printf("\nTarget was not hit in this simulation.\n");
    return 0;
}