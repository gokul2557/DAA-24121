#include <stdio.h>

int main() {
    int N;
    int f = 0, f1 = 1, fib, i;

    printf("Enter how many terms: ");
    scanf("%d", &N);

    printf("Fibonacci Series: ");

    if (N >= 1)
        printf("%d ", f);
    if (N >= 2)
        printf("%d ", f1);

    for (i = 3; i <= N; i++) {
        fib = f + f1;
        printf("%d ", fib);

        f = f1;
        f1 = fib;
    }

    return 0;
}
