#include <stdio.h>
#include <string.h>

int main() {
    char S[101];
    scanf("%s", S);
    char alphabet[26];

    for (int i = 0; i < 26; i++) {
        alphabet[i] = -1;
    }

    for (int i = 0; i < strlen(S); i++) {
        char c = S[i];
        int index = c - 'a';
        if (alphabet[index] == -1) alphabet[index] = i;
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", alphabet[i]);
    }

    return 0;
}