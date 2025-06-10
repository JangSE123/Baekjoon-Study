#include <stdio.h>

int main() {
    char word[101];
    scanf("%s", word);

    int count = 0, i = 0;

    while (word[i] != '\0') {
        if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') {
            count++;
            i += 3;
        } else if ((word[i + 1] == '=' && (word[i] == 'c' || word[i] == 's' || word[i] == 'z')) ||
                   (word[i + 1] == '-' && (word[i] == 'c' || word[i] == 'd')) ||
                   (word[i + 1] == 'j' && (word[i] == 'l' || word[i] == 'n'))) {
            count++;
            i += 2;
        } else {
            count++;
            i++;
        }
    }

    printf("%d\n", count);
    return 0;
}