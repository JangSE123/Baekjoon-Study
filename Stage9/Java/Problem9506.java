package Stage9.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem9506 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        while (true) {
            int n = Integer.parseInt(br.readLine());

            if (n == -1) break;

            int sum = 0;
            StringBuilder sb = new StringBuilder();
            sb.append(n).append(" = ");

            boolean first = true;

            for (int i = 1; i <= n / 2; i++) {
                if (n % i == 0) {
                    sum += i;
                    if (!first) sb.append(" + ");
                    sb.append(i);
                    first = false;
                }
            }

            if (sum == n) System.out.println(sb);
            else System.out.println(n + " is NOT perfect.");
        }

        br.close();
    }
}
