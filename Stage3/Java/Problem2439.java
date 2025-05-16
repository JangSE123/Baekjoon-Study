package Stage3.Java;

import java.util.Scanner;

public class Problem2439 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= N; i++) {
            sb.setLength(0);
            for (int j = 1; j <= N - i; j++) sb.append(" ");
            for (int j = 1; j <= i; j++) sb.append("*");
            System.out.println(sb);
        }

        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N - i; j++) {
        //         System.out.print(" ");
        //     }
        //     for (int j = 1; j <= i; j++) {
        //         System.out.print("*");
        //     }
        //     System.out.println();
        // }

        sc.close();
    }
}
