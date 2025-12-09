package Stage20.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Problem2580 {
    static int[][] board = new int[9][9];
    static ArrayList<int[]> blanks = new ArrayList<>();

    static void solve(int idx) {
        if (idx == blanks.size()) {
            print();
            System.exit(0);
        }

        int r = blanks.get(idx)[0];
        int c = blanks.get(idx)[1];

        for (int num = 1; num <= 9; num++) {
            if (check(r, c, num)) {
                board[r][c] = num;
                solve(idx + 1);
                board[r][c] = 0;
            }
        }
    }

    static boolean check(int r, int c, int num) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == num || board[i][c] == num) return false;
        }

        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }

        return true;
    }

    static void print() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) sb.append(board[i][j]).append(" ");
            sb.append("\n");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 0) blanks.add(new int[] {i, j});
            }
        }

        solve(0);
        br.close();
    }
}
