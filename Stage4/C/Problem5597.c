#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isSubmitted[30] = {false};

    for (int i = 0; i < 28; i++) {
        int num;
        scanf("%d", &num);
        isSubmitted[num - 1] = true;
    }

    for (int i = 0; i < 30; i++) {
        if (!isSubmitted[i]) printf("%d\n", i + 1);
    }

    return 0;
}