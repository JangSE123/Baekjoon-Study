#include <stdio.h>

int main(void) {
    int side1, side2, side3;
    while (1) {
        scanf("%d %d %d", &side1, &side2, &side3);

        if (side1 == 0 && side2 == 0 && side3 == 0) break;

        int max = side1;
        if (side2 > max) max = side2;
        if (side3 > max) max = side3;
        int sum = side1 + side2 + side3;

        if (sum - max <= max) {
            printf("Invalid\n");
        } else if (side1 == side2 && side2 == side3) {
            printf("Equilateral\n");
        } else if (side1 == side2 || side2 == side3 || side1 == side3) {
            printf("Isosceles\n");
        } else {
            printf("Scalene\n");
        }
    }

    return 0;
}