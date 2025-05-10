package Stage3.Java;

import java.util.Scanner;

public class Problem25304 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int X = sc.nextInt();
        int N = sc.nextInt();
        int totalPrice = 0;

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            totalPrice += a * b;
        }

        System.out.println(X == totalPrice ? "Yes" : "No");

        sc.close();
    }
}
