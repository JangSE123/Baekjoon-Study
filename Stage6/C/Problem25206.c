#include <stdio.h>
#include <string.h>

double getGradeValue(const char* grade) {
    if (strcmp(grade, "A+") == 0) return 4.5;
    if (strcmp(grade, "A0") == 0) return 4.0;
    if (strcmp(grade, "B+") == 0) return 3.5;
    if (strcmp(grade, "B0") == 0) return 3.0;
    if (strcmp(grade, "C+") == 0) return 2.5;
    if (strcmp(grade, "C0") == 0) return 2.0;
    if (strcmp(grade, "D+") == 0) return 1.5;
    if (strcmp(grade, "D0") == 0) return 1.0;
    if (strcmp(grade, "F")  == 0) return 0.0;
    return 0.0;
}

int main() {
    char subject[51], grade[3];
    double credit;
    double totalScore = 0.0;
    double totalCredit = 0.0;

    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", subject, &credit, grade);

        if (strcmp(grade, "P")) {
            totalScore += credit * getGradeValue(grade);
            totalCredit += credit;
        }
    }

    double average = totalScore / totalCredit;

    printf("%.6f\n", average);
    return 0;
}