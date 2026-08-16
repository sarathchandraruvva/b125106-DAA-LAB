#include<stdio.h>
int Binarysearch(int arr[],int n,int x,int* comparisions){
    int low = 0;
    int high = n-1;
    *comparisions = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        (*comparisions)++;
        if(x==arr[mid]){
            return mid;
        }
        (*comparisions)++;
        if(x<arr[mid]){
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int Ternarysearch(int arr[],int n,int x,int* comparisions){
    int low = 0;
    int high = n-1;
    *comparisions = 0;
    while(low<=high){
        int mid1 = low +(high-low)/3;
        int mid2 = low + 2*(high-low)/3;
        (*comparisions)++;
        if(x==arr[mid1]){
            return mid1;
        }
        (*comparisions)++;
        if(arr[mid2]==x){
            return mid2;
        }
        (*comparisions)++;
        if(x<arr[mid1]){
            high = mid1 - 1;
        }
        else if(x>arr[mid1] && x<arr[mid2]){
            low = mid1+1;
            high = mid2-1;
        }
        else{
            low = mid2+1;
        }
    }
    return -1;
}
int main(){
    int n,x;
    printf("enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the element u have to search: ");
    scanf("%d",&x);
    int arr[n];
    printf("'enter the sorted array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int binarycomparisions;
    int ternarycomparisions;

    int bresult = Binarysearch(arr,n,x,&binarycomparisions);
    int tresult = Ternarysearch(arr,n,x,&ternarycomparisions);
    if(bresult!=-1){
        printf("Binary search Element found at index : %d\n",bresult);
    }
    else{
        printf("The binary search element not found\n");
    }
    printf("the binary search comparisions = %d\n",binarycomparisions);
    if(tresult!=0){
        printf("ternary search element found at index: %d\n",tresult);
    }
    else{
        printf("in ternary search element not found\n");
    }
    printf("The ternary search comparisions = %d",ternarycomparisions);
    printf("\n------COMPARISONS-----\n");
    if(binarycomparisions<ternarycomparisions){
        printf("Binary search is better as there are fewer comparisions than ternary search");
    }
    else if(binarycomparisions>ternarycomparisions){
        printf("Ternary search is better as there are fewer comparisions than Binary search");
    }
    else{
        printf("both are used same comparisions");
    }
    return 0;
}