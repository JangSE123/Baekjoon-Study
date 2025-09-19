#include <stdio.h>

int main(void) {
    int X;
    scanf("%d", &X);

    int line = 1;
    int count = 0;

    while (count + line < X) {
        count += line;
        line++;
    }

    int indexLine = X - count;
    int numerator, denominator;

    if (line % 2 == 0) {
        numerator = indexLine;
        denominator = line - indexLine + 1;
    } else {
        numerator = line - indexLine + 1;
        denominator = indexLine;
    }
    
    printf("%d/%d\n", numerator, denominator);
    return 0;
}