package Stage24.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1992 {
    static int N;
    static int[][] map;
    static StringBuilder sb = new StringBuilder();

    static void quad(int x, int y, int size) {
        int first = map[x][y];
        boolean same = true;

        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (map[i][j] != first) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        if (same) {
            sb.append(first);
            return;
        }

        sb.append("(");
        int half = size / 2;

        quad(x, y, half);
        quad(x, y + half, half);
        quad(x + half, y, half);
        quad(x + half, y + half, half);

        sb.append(")");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        quad(0, 0, N);
        System.out.println(sb);
        br.close();
    }
}
