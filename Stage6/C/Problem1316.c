#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isGroupWord(const char* word) {
    bool used[26] = {false};
    char prev = word[0];
    used[prev = 'a'] = true;

    for (int i = 1; word[i] != '\0'; i++) {
        char curr = word[i];

        if (curr != prev) {

            if (used[curr - 'a']) {
                return false;
            }

            used[curr - 'a'] = true;
        }

        prev = curr;
    }

    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    int count = 0;
    char word[101];

    for (int i = 0; i < N; i++) {
        scanf("%s", word);

        if (isGroupWord(word)) {
            count++;
        }

    }

    printf("%d\n", count);
    return 0;
}