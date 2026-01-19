package Stage24.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem11444 {
    static final long MOD = 1000000007;

    static long[][] pow(long[][] matrix, long exp) {
        if (exp == 1) return matrix;

        long[][] half = pow(matrix, exp / 2);
        long[][] ret = multiply(half, half);

        if (exp % 2 == 1) {
            ret = multiply(ret, matrix);
        }

        return ret;
    }

    static long[][] multiply(long[][] a, long[][] b) {
        long[][] res = new long[2][2];

        res[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
        res[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
        res[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
        res[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        
        if (n == 0) {
            System.out.println(0);
            return;
        }

        long[][] result = pow(new long[][] {
            {1, 1}, {1, 0}
        }, n);

        System.out.println(result[0][1]);
    }
}
