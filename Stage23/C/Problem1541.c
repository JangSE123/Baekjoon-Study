#include <stdio.h>

int main(void) {
    char s[100];
    scanf("%s", s);

    int result = 0, num = 0, minus = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else {
            if (minus)
                result -= num;
            else
                result += num;
            
            if (s[i] == '-')
                minus = 1;
            
            num = 0;
        }
    }

    if (minus)
        result -= num;
    else
        result += num;
    
    printf("%d\n", result);
    return 0;
}