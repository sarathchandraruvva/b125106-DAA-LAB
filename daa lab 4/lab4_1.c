/*
SORT-BY-COLOR(A, n)

1. Create empty arrays RED, BLUE, YELLOW.

2. For i = 0 to n-1:

       If A[i].color = RED
           Add A[i] to RED

       Else if A[i].color = BLUE
           Add A[i] to BLUE

       Else
           Add A[i] to YELLOW

3. Output all elements of RED.

4. Output all elements of BLUE.

5. Output all elements of YELLOW.
*/
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RED = 0,
    BLACK = 1,
    YELLOW = 2
} color;

typedef struct {
    int num;
    color colour;
} item;

const char* colortostring(color colour) {
    switch (colour) {
        case RED:
            return "RED";

        case BLACK:
            return "BLACK";

        case YELLOW:
            return "YELLOW";

        default:
            return "Unknown";
    }
}

void sortByColour(item *arr, int n) {

    // Temporary array
    item *output = (item *)malloc(n * sizeof(item));

    int index = 0;

    // Put RED items first
    for (int i = 0; i < n; i++) {
        if (arr[i].colour == RED) {
            output[index] = arr[i];
            index++;
        }
    }

    // Put BLACK items next
    for (int i = 0; i < n; i++) {
        if (arr[i].colour == BLACK) {
            output[index] = arr[i];
            index++;
        }
    }

    // Put YELLOW items last
    for (int i = 0; i < n; i++) {
        if (arr[i].colour == YELLOW) {
            output[index] = arr[i];
            index++;
        }
    }

    // Copy sorted items back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

int main() {

    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    item *arr = (item *)malloc(n * sizeof(item));

    printf("\nEnter number and colour:\n");
    printf("0 = RED, 1 = BLACK, 2 = YELLOW\n");

    for (int i = 0; i < n; i++) {

        int c;

        printf("Item %d: ", i + 1);

        scanf("%d %d", &arr[i].num, &c);

        arr[i].colour = (color)c;
    }

    printf("\nBefore sorting:\n");

    for (int i = 0; i < n; i++) {
        printf("(%d, %s) ",
               arr[i].num,
               colortostring(arr[i].colour));
    }

    sortByColour(arr, n);

    printf("\n\nAfter sorting by colour:\n");

    for (int i = 0; i < n; i++) {
        printf("(%d, %s) ",
               arr[i].num,
               colortostring(arr[i].colour));
    }

    printf("\n");

    free(arr);

    return 0;
}