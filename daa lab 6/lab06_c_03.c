#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1)

void fft(double complex a[], int n, int invert) {
    if (n == 1)
        return;

    double complex even[n / 2];
    double complex odd[n / 2];

    for (int i = 0; i < n / 2; i++) {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    fft(even, n / 2, invert);
    fft(odd, n / 2, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    double complex w = 1;
    double complex wn = cos(angle) + I * sin(angle);

    for (int k = 0; k < n / 2; k++) {
        double complex t = w * odd[k];

        a[k] = even[k] + t;
        a[k + n / 2] = even[k] - t;

        w *= wn;
    }

    if (invert)
        for (int i = 0; i < n; i++)
            a[i] /= 2;
}

int main() {
    int m, n;

    printf("Enter length of A and B: ");
    scanf("%d %d", &m, &n);

    int L = 1;
    while (L < m + n - 1)
        L *= 2;

    double complex A[L], B[L];

    for (int i = 0; i < L; i++)
        A[i] = B[i] = 0;

    printf("Enter A:\n");
    for (int i = 0; i < m; i++) {
        double x;
        scanf("%lf", &x);
        A[i] = x;
    }

    printf("Enter B:\n");
    for (int i = 0; i < n; i++) {
        double x;
        scanf("%lf", &x);
        B[i] = x;
    }

    fft(A, L, 0);
    fft(B, L, 0);

    for (int i = 0; i < L; i++)
        A[i] *= B[i];

    fft(A, L, 1);

    printf("Convolution:\n");
    for (int i = 0; i < m + n - 1; i++)
        printf("%.2f ", creal(A[i]));

    return 0;
}