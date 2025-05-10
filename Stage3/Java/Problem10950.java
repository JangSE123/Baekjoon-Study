package Stage3.Java;

import java.util.Scanner;

public class Problem10950 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int[] results = new int[T];
        
        for (int i = 0; i < T; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            results[i] = A + B;
        }

        for (int i = 0; i < T; i++) {
            System.out.println(results[i]);
        }

        sc.close();
    }
}
