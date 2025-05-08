package Stage2.Java;

import java.util.Scanner;

public class Problem2884 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int H = sc.nextInt();
        int M = sc.nextInt();

        M -= 45;

        if (M < 0) {
            H--;
            M += 60;
            if (H < 0) {
                H += 24;
            }
        }

        System.out.println(H + " " + M);

        sc.close();
    }
}
