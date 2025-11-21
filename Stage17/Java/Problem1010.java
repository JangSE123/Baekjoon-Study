package Stage17.Java;

import java.util.Scanner;

public class Problem1010 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            long res = 1;
            for (int i = 1; i <= N; i++) {
                res = res * (M - i + 1) / i;
            }

            System.out.println(res);
        }
        sc.close();
    }
}
