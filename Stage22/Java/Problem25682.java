package Stage22.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem25682 {
    static int N, M, K;
    static char[][] board;
    static int[][] psumW, psumB;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        board = new char[N + 1][M + 1];
        psumW = new int[N + 1][M + 1];
        psumB = new int[N + 1][M + 1];

        for (int i = 1; i <= N; i++) {
            String line = br.readLine();
            for (int j = 1; j <= M; j++) {
                board[i][j] = line.charAt(j - 1);
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                boolean isWhite = (i + j) % 2 == 0;

                int w = (board[i][j] == (isWhite ? 'W' : 'B')) ? 0 : 1;
                int b = (board[i][j] == (isWhite ? 'B' : 'W')) ? 0 : 1;

                psumW[i][j] = psumW[i - 1][j] + psumW[i][j - 1]
                            - psumW[i - 1][j - 1] + w;

                psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1]
                            - psumB[i - 1][j - 1] + b;
            }
        }

        int ans = Integer.MAX_VALUE;

        for (int i = K; i <= N; i++) {
            for (int j = K; j <= M; j++) {
                int w = psumW[i][j] - psumW[i - K][j]
                      - psumW[i][j - K] + psumW[i - K][j - K];

                int b = psumB[i][j] - psumB[i - K][j]
                      - psumB[i][j - K] + psumB[i - K][j - K];

                ans = Math.min(ans, Math.min(w, b));
            }
        }

        System.out.println(ans);
        br.close();
    }
}
