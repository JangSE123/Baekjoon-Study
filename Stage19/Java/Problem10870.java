package Stage19.Java;

import java.util.Scanner;

public class Problem10870 {
    static long[] memo = new long[100];

    public static long fibonacci(int n) {
        if (n <= 1) return n;
        if (memo[n] != 0) return memo[n];
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        System.out.println(fibonacci(N));
        sc.close();
    }
}
