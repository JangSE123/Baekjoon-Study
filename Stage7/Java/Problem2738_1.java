package Stage7.Java;

import java.util.ArrayList;
import java.util.Scanner;

public class Problem2738_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        ArrayList<ArrayList<Integer>> B = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                row.add(sc.nextInt());
            }
            A.add(row);
        }

        for (int i = 0; i < N; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                row.add(sc.nextInt());
            }
            B.add(row);
        }

        for (int i = 0; i < N; i++) {
            ArrayList<Integer> rowA = A.get(i);
            ArrayList<Integer> rowB = B.get(i);

            for (int j = 0; j < M; j++) {
                int sum = rowA.get(j) + rowB.get(j);
                System.out.print(sum + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
