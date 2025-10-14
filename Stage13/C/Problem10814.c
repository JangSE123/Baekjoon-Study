#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
} Person;

int main(void) {
    int N;
    scanf("%d", &N);

    Person *people = (Person*)malloc(sizeof(Person) * N);
    for (int i = 0; i < N; i++)
        scanf("%d %s", &people[i].age, people[i].name);

    Person *bucket[201][100000];
    int count[201] = {0};

    for (int i = 0; i < N; i++) {
        int age = people[i].age;
        bucket[age][count[age]++] = &people[i];
    }

    for (int age = 1; age <= 200; age++)
        for (int i = 0; i < count[age]; i++)
            printf("%d %s\n", bucket[age][i]->age, bucket[age][i]->name);

    free(people);
    return 0;
}