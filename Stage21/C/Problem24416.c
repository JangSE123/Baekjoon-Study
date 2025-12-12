#include <stdio.h>

int countRec = 0;
int countDP = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        countRec++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    int f[50];
    f[1] = 1;
    f[2] = 1;

    for (int i = 3; i <= n; i++) {
        countDP++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(void) {
    int n;
    scanf("%d", &n);

    fib(n);
    fibonacci(n);

    printf("%d %d\n", countRec, countDP);

    return 0;
}