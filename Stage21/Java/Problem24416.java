package Stage21.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem24416 {
    static int countRec = 0;
    static int countDP = 0;

    static int fib(int n) {
        if (n == 1 || n == 2) {
            countRec++;
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
    }

    static int fibonacci(int n) {
        int[] f = new int[n + 1];
        f[1] = 1;
        f[2] = 1;

        for (int i = 3; i <= n; i++) {
            countDP++;
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        fib(n);
        fibonacci(n);

        System.out.println(countRec + " " + countDP);
    }
}
