package Stage31.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem11062 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            int[] cards = new int[N];
            int sum = 0;

            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                cards[i] = Integer.parseInt(st.nextToken());
                sum += cards[i];
            }

            int[][] dp = new int[N][N];

            for (int i = 0; i < N; i++) {
                dp[i][i] = cards[i];
            }

            for (int len = 2; len <= N; len++) {
                for (int l = 0; l + len - 1 < N; l++) {
                    int r = l + len - 1;

                    dp[l][r] = Math.max(cards[l] - dp[l + 1][r], cards[r] - dp[l][r - 1]);
                }
            }

            int result = (sum + dp[0][N - 1]) / 2;
            sb.append(result).append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}
