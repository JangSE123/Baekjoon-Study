#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char word[1000001];
    scanf("%s", word);
    int alphabet[26] = {0};
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) {
        alphabet[toupper(word[i]) - 'A']++;
    }

    int maxValue = 0;
    char result = '?';

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > maxValue) {
            maxValue = alphabet[i];
            result = i + 'A';
        } else if (alphabet[i] == maxValue) {
            result = '?';
        }
    }

    printf("%c\n", result);
    return 0;
}