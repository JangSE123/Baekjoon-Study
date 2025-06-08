package Stage6.Java;

import java.util.Scanner;

public class Problem2444 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            System.out.print(" ".repeat(N - i - 1));
            System.out.println("*".repeat(2 * i + 1));
        }

        for (int i = N - 2; i >= 0; i--) {
            System.out.print(" ".repeat(N - i - 1));
            System.out.println("*".repeat(2 * i + 1));
        }

        sc.close();
    }
}