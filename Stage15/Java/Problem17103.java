package Stage15.Java;

import java.util.Arrays;
import java.util.Scanner;

public class Problem17103 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int T = sc.nextInt();
        int MAX = 1000000;

        boolean[] isPrime = new boolean[MAX + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= MAX; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int count = 0;

            if (isPrime[2] && isPrime[N - 2]) count++;

            for (int j = 3; j <= N / 2; j += 2) {
                if (isPrime[j] && isPrime[N - j]) count++;
            }
            sb.append(count).append("\n");
        }

        System.out.println(sb);
        sc.close();
    }
}
