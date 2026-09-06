#include <stdio.h>
#include <math.h>
#include <limits.h>
void findMaximum(int a[], int n){
    int i, max = a[0];
    for(i = 1; i < n; i++){
        if(a[i] > max)
            max = a[i];
    }
    printf("Maximum element = %d\n", max);
}
void findLargestTwo(int a[], int n){
    int i;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for(i = 0; i < n; i++){
        if(a[i] > largest){
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] > secondLargest && a[i] != largest){
            secondLargest = a[i];
        }
    }
    printf("Largest element = %d\n", largest);
    printf("Second largest element = %d\n", secondLargest);
}
void findMean(int a[], int n){
    int i;
    float sum = 0, mean;
    for(i = 0; i < n; i++)
        sum = sum + a[i];
    mean = sum / n;
    printf("Mean = %.2f\n", mean);
}
void findMedian(int a[], int n){
    int i, j, temp;
    float median;
    int b[n];
    for(i = 0; i < n; i++)
        b[i] = a[i];
    /* Sorting the array */
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(b[j] > b[j + 1]){
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    if(n % 2 == 1)
        median = b[n / 2];
    else
        median = (b[n / 2 - 1] + b[n / 2]) / 2.0;
    printf("Median = %.2f\n", median);
}
void findStandardDeviation(int a[], int n){
    int i;
    float sum = 0, mean, variance = 0, sd;
    for(i = 0; i < n; i++)
        sum = sum + a[i];
    mean = sum / n;
    for(i = 0; i < n; i++)
        variance = variance + (a[i] - mean) * (a[i] - mean);
    variance = variance / n;
    sd = sqrt(variance);
    printf("Standard deviation = %.2f\n", sd);
}
void findMode(int a[], int n){
    int i, j;
    int count, maxCount = 0, mode = a[0];
    for(i = 0; i < n; i++){
        count = 0;
        for(j = 0; j < n; j++){
            if(a[i] == a[j])
                count++;
        }
        if(count > maxCount){
            maxCount = count;
            mode = a[i];
        }
    }
    if(maxCount == 1)
        printf("No mode (all elements occur only once)\n");
    else
        printf("Mode = %d\n", mode);
}
void removeDuplicates(int a[], int *n){
    int i, j, k;
    for(i = 0; i < *n; i++){
        for(j = i + 1; j < *n; j++){
            if(a[i] == a[j]){
                for(k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];
                (*n)--;
                j--;
            }
        }
    }
    printf("Array after removing duplicates:\n");
    for(i = 0; i < *n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void reverseArray(int a[], int n){
    int i, j, temp;
    i = 0;
    j = n - 1;
    while(i < j){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    printf("Reversed array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void partitionArray(int a[], int n){
    int i, j, pivot, temp;
    pivot = a[n - 1];
    i = 0;
    for(j = 0; j < n - 1; j++){
        if(a[j] < pivot){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    temp = a[i];
    a[i] = a[n - 1];
    a[n - 1] = temp;
    printf("Pivot = %d\n", pivot);
    printf("Partitioned array:\n");
    for(j = 0; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");
}
int main(){
    int n, i, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    do{
        printf("\n========== MENU ==========\n");
        printf("1. Find Maximum Element\n");
        printf("2. Find First and Second Largest\n");
        printf("3. Find Mean\n");
        printf("4. Find Median\n");
        printf("5. Find Standard Deviation\n");
        printf("6. Find Mode\n");
        printf("7. Remove All Duplicates\n");
        printf("8. Reverse Array\n");
        printf("9. Partition Around Pivot\n");
        printf("10. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                findMaximum(a, n);
                break;
            case 2:
                findLargestTwo(a, n);
                break;
            case 3:
                findMean(a, n);
                break;
            case 4:
                findMedian(a, n);
                break;
            case 5:
                findStandardDeviation(a, n);
                break;
            case 6:
                findMode(a, n);
                break;
            case 7:
                removeDuplicates(a, &n);
                break;
            case 8:
                reverseArray(a, n);
                break;
            case 9:
                partitionArray(a, n);
                break;
            case 10:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 10);
    return 0;
}