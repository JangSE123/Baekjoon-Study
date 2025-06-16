package Stage7.Java;

import java.util.Scanner;

public class Problem10798 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] arr = new char[5][15];

        for (int i = 0; i < 5; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < line.length(); j++) {
                arr[i][j] = line.charAt(j);
            }
        }

        for (int j = 0; j < 15; j++) {
            for (int i = 0; i < 5; i++) {
                if (arr[i][j] != '\0') {
                    System.out.print(arr[i][j]);
                }
            }
        }

        sc.close();
    }
}
