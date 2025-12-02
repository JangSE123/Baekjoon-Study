package Stage19.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem2447 {
    static char [][] board;

    static void draw(int x, int y, int size) {
        if (size == 1) return;

        int newSize = size / 3;

        for (int i = x + newSize; i < x + 2 * newSize; i++) {
            for (int j = y + newSize; j < y + 2 * newSize; j++) {
                board[i][j] = ' ';
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) continue;
                draw(x + i * newSize, y + j * newSize, newSize);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

        board = new char[N][N];
        for (int i = 0; i < N; i++) {
            Arrays.fill(board[i], '*');
        }

        draw(0, 0, N);

        for (int i = 0; i < N; i++) {
            sb.append(board[i]).append('\n');
        }

        System.out.println(sb);
        br.close();
    }
}
