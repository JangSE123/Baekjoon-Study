#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    scanf("%s", word);
    int len = strlen(word);
    int isSame = 1;

    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) isSame = 0;
    }

    printf("%d\n", isSame);
    return 0;
}