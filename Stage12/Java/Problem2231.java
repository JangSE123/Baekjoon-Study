package Stage12.Java;

import java.util.Scanner;

public class Problem2231 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int result = 0;
        int start = N - 9 * String.valueOf(N).length();
        if (start < 1) start = 1;

        for (int i = start; i < N; i++) {
            int sum = i;
            int temp = i;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            if (sum == N) {
                result = i;
                break;
            }
        }

        System.out.println(result);
        sc.close();
    }
}
