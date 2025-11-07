#include <stdio.h>
#define MAX 100000

int main(void) {
    int K;
    scanf("%d", &K);
    
    int stack[MAX];
    int top = 0;

    while (K-- > 0) {
        int num;
        scanf("%d", &num);

        if (num == 0) top--;
        else stack[top++] = num;
    }

    int result = 0;
    
    for (int i = 0; i < top; i++) {
        result += stack[i];
    }

    printf("%d\n", result);
    return 0;
}