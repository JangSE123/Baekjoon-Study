package Stage31.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2629 {
    static boolean[] dp = new boolean[15001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] weights = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            weights[i] = Integer.parseInt(st.nextToken());
        }

        dp[0] = true;

        for (int i = 0; i < N; i++) {
            boolean[] next = new boolean[15001];

            for (int w = 0; w <= 15000; w++) {
                if (!dp[w]) continue;

                next[w] = true;

                if (w + weights[i] <= 15000)
                    next[w + weights[i]] = true;

                next[Math.abs(w - weights[i])] = true;
            }

            dp = next;
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        while (M-- > 0) {
            int bead = Integer.parseInt(st.nextToken());

            if (bead > 15000) sb.append("N ");
            else sb.append(dp[bead] ? "Y " : "N ");
        }

        System.out.println(sb);
        br.close();
    }
}
