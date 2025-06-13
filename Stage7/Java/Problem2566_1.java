package Stage7.Java;

import java.util.Scanner;

class Position {
    int row, col, value;

    Position(int row, int col, int value) {
        this.row = row;
        this.col = col;
        this.value = value;
    }
}

public class Problem2566_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] matrix = new int[9][9];
        Position max = new Position(0, 0, Integer.MIN_VALUE);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = sc.nextInt();
                if (matrix[i][j] > max.value) max = new Position(i + 1, j + 1, matrix[i][j]);
            }
        }

        System.out.println(max.value);
        System.out.println(max.row + " " + max.col);
        sc.close();
    }
}
