package Stage24.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1629 {
    static long A, B, C;

    static long power(long a, long b) {
        if (b == 1) {
            return a % C;
        }

        long half = power(a, b / 2);

        if (b % 2 == 0) {
            return (half * half) % C;
        } else {
            return (half * half % C * a) % C;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());
        C = Long.parseLong(st.nextToken());

        System.out.println(power(A, B));
        br.close();
    }
}
