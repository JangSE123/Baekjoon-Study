package Stage4.Java;

import java.util.Scanner;

public class Problem5597 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        boolean[] isSubmitted = new boolean[30];

        for (int i = 0; i < 28; i++) {
            int num = sc.nextInt();
            isSubmitted[num - 1] = true;
        }

        for (int i = 0; i < 30; i++) {
            if (!isSubmitted[i]) {
                System.out.println(i + 1);
            }
        }

        sc.close();
    }
}
