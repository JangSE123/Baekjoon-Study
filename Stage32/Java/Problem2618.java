package Stage32.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem2618 {
    static int N, W;
    static int[][] event;
    static int[][] dp;
    static int[][] path;

    static int dist(int from, int to, int type) {
        int x1, y1;

        if (from == 0) {
            if (type == 1) {
                x1 = 1; y1 = 1;
            } else {
                x1 = N; y1 = N;
            }
        } else {
            x1 = event[from][0];
            y1 = event[from][1];
        }

        int x2 = event[to][0];
        int y2 = event[to][1];

        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    static int solve(int a, int b) {
        if (a == W || b == W) return 0;

        if (dp[a][b] != -1) return dp[a][b];

        int next = Math.max(a, b) + 1;

        int case1 = solve(next, b) + dist(a, next, 1);

        int case2 = solve(a, next) + dist(b, next, 2);

        if (case1 < case2) {
            path[a][b] = 1;
            return dp[a][b] = case1;
        } else {
            path[a][b] = 2;
            return dp[a][b] = case2;
        }
    }

    static void trace(int a, int b) {
        if (a == W || b == W) return;

        int next = Math.max(a, b) + 1;

        if (path[a][b] == 1) {
            System.out.println(1);
            trace(next, b);
        } else {
            System.out.println(2);
            trace(a, next);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        W = Integer.parseInt(br.readLine());

        event = new int[W + 1][2];
        dp = new int[W + 1][W + 1];
        path = new int[W + 1][W + 1];

        for (int i = 0; i <= W; i++) {
            Arrays.fill(dp[i], -1);
        }

        for (int i = 1; i <= W; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            event[i][0] = Integer.parseInt(st.nextToken());
            event[i][1] = Integer.parseInt(st.nextToken());
        }

        System.out.println(solve(0, 0));
        trace(0, 0);
        br.close();
    }
}
