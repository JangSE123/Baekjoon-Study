package Stage7.Java;

import java.util.Scanner;

public class Problem2566 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] matrix = new int[9][9];
        int value = Integer.MIN_VALUE, row = 0, col = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (matrix[i][j] > value) {
                    value = matrix[i][j];
                    row = i + 1;
                    col = j + 1;
                } 
            }
        }

        System.out.println(value);
        System.out.println(row + " " + col);
        sc.close();
    }
}
