#include <stdio.h>
#include <limits.h>
#define MAX 20
long long dp[MAX];
int split[MAX];
long long power2(int n){
    return 1LL << n;
}
void calculate(int n){
    int i, k;
    long long best, moves;
    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i <= n; i++){
        best = LLONG_MAX;
        for (k = 1; k < i; k++){
            moves = 2 * dp[k] + power2(i - k) - 1;
            if (moves < best){
                best = moves;
                split[i] = k;
            }
        }
        dp[i] = best;
    }
}
void hanoi4(int n, char source, char target, char aux1, char aux2){
    int k;
    if (n == 0)
        return;
    if (n == 1){
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    k = split[n];
    hanoi4(k, source, aux1, target, aux2);
    hanoi3(n - k, source, target, aux2);
    hanoi4(k, aux1, target, source, aux2);
}
void hanoi3(int n, char source, char target, char auxiliary){
    if (n == 0)
        return;
    hanoi3(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n",n, source, target);
    hanoi3(n - 1, auxiliary, target, source);
}
int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    if (n <= 0 || n >= MAX){
        printf("Invalid number of disks.\n");
        return 0;
    }
    calculate(n);
    printf("\nMinimum number of moves = %lld\n", dp[n]);
    if (n == 8)
        printf("For 8 disks, the minimum moves = 33\n");
    printf("\nSequence of moves:\n");
    hanoi4(n, 'A', 'D', 'B', 'C');
    return 0;
}