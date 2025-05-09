package Stage2.Java;

import java.util.Scanner;

public class Problem2480 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int dice1 = sc.nextInt();
        int dice2 = sc.nextInt();
        int dice3 = sc.nextInt();

        int reward;

        if (dice1 == dice2 && dice2 == dice3) {
            reward = 10000 + dice1 * 1000;
        } else if (dice1 == dice2 || dice2 == dice3 || dice1 == dice3) {
            int sameValue = (dice1 == dice2 || dice1 == dice3) ? dice1 : dice2;
            reward = 1000 + sameValue * 100;
        } else {
            reward = Math.max(dice1, Math.max(dice2, dice3)) * 100;
        }

        System.out.println(reward);

        sc.close();
    }
}
