#include <stdio.h>

#define MAX 2000000

int main() {
    int N, cmd, X;
    scanf("%d", &N);

    int deq[MAX];
    int front = MAX/2, back = MAX/2;

    while (N--) {
        scanf("%d", &cmd);

        switch (cmd) {
            case 1:
                scanf("%d", &X);
                deq[--front] = X;
                break;

            case 2:
                scanf("%d", &X);
                deq[back++] = X;
                break;

            case 3:
                if (front == back) printf("-1\n");
                else printf("%d\n", deq[front++]);
                break;

            case 4:
                if (front == back) printf("-1\n");
                else printf("%d\n", deq[--back]);
                break;

            case 5:
                printf("%d\n", back - front);
                break;

            case 6:
                printf("%d\n", (front == back) ? 1 : 0);
                break;

            case 7:
                if (front == back) printf("-1\n");
                else printf("%d\n", deq[front]);
                break;

            case 8:
                if (front == back) printf("-1\n");
                else printf("%d\n", deq[back - 1]);
                break;
        }
    }

    return 0;
}