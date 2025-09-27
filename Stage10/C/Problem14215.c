#include <stdio.h>

int main(void) {
    int side1, side2, side3;
    scanf("%d %d %d", &side1, &side2, &side3);

    if (side1 > side2) { int tmp = side1; side1 = side2; side2 = tmp; }
    if (side2 > side3) { int tmp = side2; side2 = side3; side3 = tmp; }
    if (side1 > side2) { int tmp = side1; side1 = side2; side2 = tmp; }

    int x = side1, y = side2, z = side3;

    if (x + y > z) {
        printf("%d\n", x + y + z);
    } else {
        printf("%d\n", 2 * (x + y) - 1);
    }

    return 0;
}