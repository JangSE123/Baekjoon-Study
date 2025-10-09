#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main(void) {
    char num[12];
    scanf("%s", num);

    int len = strlen(num);

    qsort(num, len, sizeof(char), compare);

    printf("%s", num);
    return 0;
}