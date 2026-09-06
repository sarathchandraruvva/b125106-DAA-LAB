#include <stdio.h>

#define MAX 100

void reverse(int p[], int l, int r) {
    while (l < r) {
        int temp = p[l];
        p[l] = p[r];
        p[r] = temp;
        l++;
        r--;
    }
}

void rotate(int p[], int l, int mid, int r) {
    reverse(p, l, mid);
    reverse(p, mid + 1, r);
    reverse(p, l, r);
}

int binarySearch(int p[], int l, int r, int key) {
    while (l < r) {
        int mid = (l + r) / 2;

        if (p[mid] < key)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

void merge(int p[], int l, int mid, int r) {
    if (l > mid || mid + 1 > r)
        return;

    if (p[mid] <= p[mid + 1])
        return;

    if (r - l == 1) {
        if (p[l] > p[r]) {
            int temp = p[l];
            p[l] = p[r];
            p[r] = temp;
        }
        return;
    }

    int first, second, cut1, cut2;

    if (mid - l > r - mid) {
        cut1 = (l + mid) / 2;
        int key = p[cut1];

        cut2 = binarySearch(p, mid + 1, r, key);

        first = cut1;
        second = cut2;
    } else {
        cut2 = (mid + 1 + r) / 2;
        int key = p[cut2];

        cut1 = binarySearch(p, l, mid + 1, key);

        first = cut1;
        second = cut2;
    }

    rotate(p, first, mid, second - 1);

    int newMid = first + (second - mid - 1);

    merge(p, l, first - 1, newMid);
    merge(p, newMid + 1, second - 1, r);
}

void mergeSort(int p[], int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(p, l, mid);
    mergeSort(p, mid + 1, r);

    merge(p, l, mid, r);
}

int main() {
    int p[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter permutation:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    mergeSort(p, 0, n - 1);

    printf("Sorted permutation:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    return 0;
}