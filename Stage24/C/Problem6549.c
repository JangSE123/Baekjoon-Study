#include <stdio.h>

int main(void) {
    while(1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        long long h[100000];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &h[i]);
        }

        int stack[100000];
        int top = -1;
        long long max = 0;

        for (int i = 0; i < n; i++) {
            while (top != -1 && h[stack[top]] > h[i]) {
                int heightIdx = stack[top--];
                long long height = h[heightIdx];

                int width;
                if (top == -1) {
                    width = i;
                } else {
                    width = i - stack[top] - 1;
                }

                long long area = height * width;
                if (area > max) max = area;
            }
            stack[++top] = i;
        }

        while (top != -1) {
            int heightIdx = stack[top--];
            long long height = h[heightIdx];

            int width;
            if (top == -1) {
                width = n;
            } else {
                width = n - stack[top] - 1;
            }

            long long area = height * width;
            if (area > max) max = area;
        }

        printf("%lld\n", max);
    }

    return 0;
}