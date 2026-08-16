#include<stdio.h>
int getweight(int coins[],int l,int r){
    int sum = 0;
    int i;
    for(i<l;i<=r;i++){
        sum = sum + coins[i];
    }
    return sum;
}
int finddefective(int coins[],int left,int right){
    int mid;
    int leftweight,rightweight;
    if(left==right){
        if(coins[left]<10){
            return left;
        }
        else{
            return -1;
        }
    }
    mid = (left+right)/2;
    leftweight = getweight(coins,left,mid);
    rightweight = getweight(coins,mid+1,right);
    if(leftweight < rightweight){
        return finddefective(coins,left,mid);
    }
    else if(rightweight<leftweight){
        return finddefective(coins,mid+1,right);
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    int i;
    int result;
    printf("enter the number of coins: ");
    scanf("%d",&n);
    int coins[n];
    printf("Enter weights of coins: ");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    result = finddefective(coins,0,n-1);
    if(result == -1){
        printf("\n No defective coin found \n");
    }
    else{
        printf("\n Defective coin found at position %d\n",result+1);
        printf("Weight of defective coin: %d\n",coins[result]);
    }
    return 0;
}