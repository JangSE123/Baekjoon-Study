#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char N[32];
    int B, result = 0, power = 1;
    scanf("%s %d", N, &B);
    int length = strlen(N);

    for (int i = length - 1; i >= 0; i--) {
        char c = toupper(N[i]);
        int value;

        if (c >= '0' && c <= '9') {
            value = N[i] - '0';
        } else {
            value = N[i] - 'A' + 10;
        }

        result += value * power;
        power *= B;
    }

    printf("%d", result);
    return 0;
}
