package Stage4.Java;

import java.util.Scanner;

public class Problem10811 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }

        for (int x = 0; x < M; x++) {
            int i = sc.nextInt();
            int j = sc.nextInt();

            int left = i - 1;
            int right = j - 1;

            while (left < right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }

        for (int num : arr) System.out.print(num + " ");

        sc.close();
    }
}
