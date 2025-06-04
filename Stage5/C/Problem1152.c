#include <stdio.h>
#include <string.h>

int main() {
    char text[1000001];
    int count = 0;
    
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    char *token = strtok(text, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    printf("%d\n", count);
    return 0;
}