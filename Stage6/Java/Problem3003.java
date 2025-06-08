package Stage6.Java;

import java.util.Scanner;

public class Problem3003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] defaultPieces = {1, 1, 2, 2, 2, 8};

        for (int piece : defaultPieces) {
            System.out.print((piece - sc.nextInt()) + " ");
        }

        sc.close();
    }
}
