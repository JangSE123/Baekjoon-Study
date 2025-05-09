#include <stdio.h>

int main() {
    int dice1, dice2, dice3, reward;

    scanf("%d %d %d", &dice1, &dice2, &dice3);

    if (dice1 == dice2 && dice2 == dice3) {
        reward = 10000 + dice1 * 1000;
    } else if (dice1 == dice2 || dice2 == dice3 || dice1 == dice3) {
        int sameValue = (dice1 == dice2 || dice1 == dice3) ? dice1 : dice2;
        reward = 1000 + sameValue * 100;
    } else {
        int maxValue = dice1;
        if (dice2 > maxValue) maxValue = dice2;
        if (dice3 > maxValue) maxValue = dice3;
        reward = maxValue * 100;
    }

    printf("%d\n", reward);

    return 0;
}