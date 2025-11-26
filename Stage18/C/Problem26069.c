#include <stdio.h>
#include <string.h>

#define MAX 2000
#define LEN 25

int main(void) {
    int N;
    scanf("%d", &N);

    char people[MAX][LEN];
    int count = 1;
    strcpy(people[0], "ChongChong");

    while (N--) {
        char a[LEN], b[LEN];
        scanf("%s %s", a, b);

        int aDance = 0, bDance = 0;

        for (int i = 0; i < count; i++)
            if (strcmp(people[i], a) == 0)
                aDance = 1;

        for (int i = 0; i < count; i++)
            if (strcmp(people[i], b) == 0)
                bDance = 1;

        if (aDance || bDance) {
            if (!aDance) strcpy(people[count++], a);
            if (!bDance) strcpy(people[count++], b);
        }
    }

    printf("%d\n", count);
    return 0;
}