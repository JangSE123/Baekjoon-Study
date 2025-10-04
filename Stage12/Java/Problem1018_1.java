package Stage12.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1018_1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
    
        char[][] board = new char[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }

        int answer = 64;
        for (int x = 0; x <= N - 8; x++) {
            for (int y = 0; y <= M - 8; y++) {
                int cnt1 = 0, cnt2 = 0;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        char expected1 = ((i + j) % 2 == 0) ? 'W' : 'B';
                        char expected2 = ((i + j) % 2 == 0) ? 'B' : 'W';
                        if (board[x + i][y + j] != expected1) cnt1++;
                        if (board[x + i][y + j] != expected2) cnt2++;
                    }
                }
                answer = Math.min(answer, Math.min(cnt1, cnt2));
            }
        }
    
        System.out.println(answer);
        br.close();
    }
}
