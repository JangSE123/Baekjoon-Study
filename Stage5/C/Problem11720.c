#include <stdio.h>

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    char ch[N];
    scanf("%s", ch);

    for (int i = 0; i < N; i++) {
        sum += ch[i] - '0';
    }

    printf("%d", sum);

    return 0;
}