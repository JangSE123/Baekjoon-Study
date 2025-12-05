package Stage20.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem9663 {
    static int N;
    static int[] col;
    static int count = 0;

    static void dfs(int row) {
        if (row == N) {
            count++;
            return;
        }

        for (int i = 0; i < N; i++) {
            col[row] = i;
            if (isPossible(row)) {
                dfs(row + 1);
            }
        }
    }

    static boolean isPossible(int row) {
        for (int i = 0; i < row; i++) {
            if (col[i] == col[row] || Math.abs(col[i] - col[row]) == row - i) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        col = new int[N];
        dfs(0);

        System.out.println(count);
        br.close();
    }
}
