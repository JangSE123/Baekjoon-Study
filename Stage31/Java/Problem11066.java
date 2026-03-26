package Stage31.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem11066 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int K = Integer.parseInt(br.readLine());

            long [] arr = new long[K + 1];
            long[] sum = new long[K + 1];
            long[][] dp = new long[K + 1][K + 1];

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= K; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 1; i <= K; i++) {
                sum[i] = sum[i - 1] + arr[i];
            }

            for (int len = 2; len <= K; len++) {
                for (int i = 1; i <= K - len + 1; i++) {
                    int j = i + len - 1;
                    dp[i][j] = Long.MAX_VALUE;

                    for (int k = i; k < j; k++) {
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }

                    dp[i][j] += sum[j] - sum[i - 1];
                }
            }

            sb.append(dp[1][K]).append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}
