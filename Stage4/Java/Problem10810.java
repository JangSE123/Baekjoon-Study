package Stage4.Java;

import java.util.Scanner;

public class Problem10810 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] arr = new int[N];

        for (int x = 0; x < M; x++) {
            int i = sc.nextInt();
            int j = sc.nextInt();
            int k = sc.nextInt();

            for (int index = i - 1; index <= j - 1; index++) {
                arr[index] = k;
            }
        }

        for (int num : arr) {
            System.out.print(num + " ");
        }

        sc.close();
    }
}
