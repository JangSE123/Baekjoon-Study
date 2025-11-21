package Stage17.Java;

import java.util.Scanner;

public class Problem11050 {
    public static int factorial(int N) {
        int result = 1;
        
        for (int i = 1; i <= N; i++) {
            result *= i;
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int K = sc.nextInt();
        int result = factorial(N) / (factorial(K) * factorial(N - K));

        System.out.println(result);
        sc.close();
    }
}
