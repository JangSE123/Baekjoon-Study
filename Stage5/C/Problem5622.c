#include <stdio.h>
#include <string.h>

int main() {
    char word[16];
    int totalTime = 0;
    scanf("%s", word);

    for (int i = 0; i < strlen(word); i++) {
        switch (word[i]) {
            case 'A': case 'B': case 'C':
                totalTime += 3;
                break;
            case 'D': case 'E': case 'F':
                totalTime += 4;
                break;
            case 'G': case 'H': case 'I':
                totalTime += 5;
                break;
            case 'J': case 'K': case 'L':
                totalTime += 6;
                break;
            case 'M': case 'N': case 'O':
                totalTime += 7;
                break;
            case 'P': case 'Q': case 'R': case 'S':
                totalTime += 8;
                break;
            case 'T': case 'U': case 'V':
                totalTime += 9;
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                totalTime += 10;
                break;
        }
    }

    printf("%d", totalTime);
    return 0;
}