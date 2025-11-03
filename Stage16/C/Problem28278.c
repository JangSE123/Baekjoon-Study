#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main(void) {
    int N;
    scanf("%d", &N);

    int stack[MAX];
    int top = -1;

    for (int i = 0; i < N; i++) {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd) {
            case 1:{
                int X;
                scanf("%d", &X);
                stack[++top] = X;
                break;
            }
            case 2:
                printf("%d\n", top == -1 ? -1 : stack[top--]);
                break;
            case 3:
                printf("%d\n", top + 1);
                break;
            case 4:
                printf("%d\n", top == -1 ? 1 : 0);
                break;
            case 5:
                printf("%d\n", top == -1 ? -1 : stack[top]);
                break;
        }
    }

    return 0;
}