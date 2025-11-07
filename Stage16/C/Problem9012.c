#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        char str[51];
        scanf("%s", str);

        int stack[51];
        int top = 0;
        int valid = 1;

        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(') {
                stack[top++] = '(';
            } else {
                if (top == 0) {
                    valid = 0;
                    break;
                }
                top--;
            }
        }

        if (valid && top == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}