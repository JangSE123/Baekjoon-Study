// 시간 초과 오류가 있음
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    char name[6];
} Person;

int compare(const void *a, const void *b) {
    return strcmp(((Person*)b)->name, ((Person*)a)->name);
}

int main(void) {
    int n;
    scanf("%d", &n);

    Person people[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        char name[6];
        char action[6];
        scanf("%s %s", name, action);

        if (strcmp(action, "enter") == 0) {
            strcpy(people[count++].name, name);
        } else {
            for (int j = 0; j < count; j++) {
                if (strcmp(people[j].name, name) == 0) {
                    strcpy(people[j].name, people[count - 1].name);
                    count--;
                    break;
                }
            }
        }
    }

    qsort(people, count, sizeof(Person), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", people[i].name);
    }

    return 0;
}