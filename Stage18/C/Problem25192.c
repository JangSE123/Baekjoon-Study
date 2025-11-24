#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    char name[25];
    int count = 0;

    char seen[100000][25];
    int seen_cnt = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", name);

        if (strcmp(name, "ENTER") == 0) {
            seen_cnt = 0;
        } else {
            int found = 0;
            for (int j = 0; j < seen_cnt; j++) {
                if (strcmp(seen[j], name) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strcpy(seen[seen_cnt++], name);
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}