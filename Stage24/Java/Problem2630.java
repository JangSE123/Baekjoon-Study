package Stage24.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2630 {
    static int N;
    static int[][] paper;
    static int white = 0;
    static int blue = 0;

    static void check(int x, int y, int size) {
        int color = paper[x][y];

        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (paper[i][j] != color) {
                    int half = size / 2;
                    check(x, y, half);
                    check(x, y + half, half);
                    check(x + half, y, half);
                    check(x + half, y + half, half);
                    return;
                }
            }
        }
        
        if (color == 0) white++;
        else blue++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        paper = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        check(0, 0, N);

        System.out.println(white);
        System.out.println(blue);
        br.close();
    }
}
