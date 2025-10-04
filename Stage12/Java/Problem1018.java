package Stage12.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1018 {
    static char[][] board;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
    
        board = new char[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        int result = Integer.MAX_VALUE;
        for (int i = 0; i <= N - 8; i++) {
            for (int j = 0; j <= M - 8; j++) {
                result = Math.min(result, repaintCount(i, j));
            }
        }

        System.out.println(result);
        br.close();
    }

    private static int repaintCount(int x, int y) {
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char current = board[x + i][y + j];

                if ((i + j) % 2 == 0) {
                    if (current != 'W') cnt1++;
                    if (current != 'B') cnt2++;
                } else {
                    if (current != 'B') cnt1++;
                    if (current != 'W') cnt2++;
                }
            }
        }

        return Math.min(cnt1, cnt2);
    }
}
