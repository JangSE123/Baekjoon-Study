#include <stdio.h>

#define MOD 1000000007LL

typedef struct {
    long long a[2][2];
} Matrix;

Matrix multiply(Matrix x, Matrix y) {
    Matrix r;

    r.a[0][0] = (x.a[0][0]*y.a[0][0] + x.a[0][1]*y.a[1][0]) % MOD;
    r.a[0][1] = (x.a[0][0]*y.a[0][1] + x.a[0][1]*y.a[1][1]) % MOD;
    r.a[1][0] = (x.a[1][0]*y.a[0][0] + x.a[1][1]*y.a[1][0]) % MOD;
    r.a[1][1] = (x.a[1][0]*y.a[0][1] + x.a[1][1]*y.a[1][1]) % MOD;

    return r;
}

Matrix power(Matrix base, long long exp) {
    if (exp == 1) return base;

    Matrix half = power(base, exp / 2);
    Matrix ret = multiply(half, half);

    if (exp % 2 == 1)
        ret = multiply(ret, base);

    return ret;
}

int main(void) {
    long long n;
    scanf("%lld", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix result = power(base, n);

    printf("%lld\n", result.a[0][1]);
    return 0;
}