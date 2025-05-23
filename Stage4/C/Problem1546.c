#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    double M = 0;
    double scores[N];

    for (int i = 0; i < N; i++) {
        scanf("%lf", &scores[i]);
        if (scores[i] > M) M = scores[i];
    }

    double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += (scores[i] / M) * 100;
    }
    
    printf("%f", sum / N);
    return 0;
}