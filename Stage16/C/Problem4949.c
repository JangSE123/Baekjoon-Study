#include <stdio.h>
#include <string.h>

int main(void) {
    char str[105];

    while (1) {
        fgets(str, sizeof(str), stdin);
        if (strcmp(str, ".\n") == 0 || strcmp(str, ".") == 0) break;

        char stack[105];
        int top = 0;
        int valid = 1;

        for (int i = 0; i < strlen(str); i++) {
            char c = str[i];
            if (c == '(' || c == '[') {
                stack[top++] = c;
            } else if (c == ')') {
                if (top == 0 || stack[top - 1] != '(') {
                    valid = 0;
                    break;
                }
                top--;
            } else if (c == ']') {
                if (top == 0 || stack[top - 1] != '[') {
                    valid = 0;
                    break;
                }
                top--;
            }
        }

        if (valid && top == 0)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}