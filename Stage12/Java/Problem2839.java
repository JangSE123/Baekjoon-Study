package Stage12.Java;

import java.util.Scanner;

public class Problem2839 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int result = -1;

        for (int i = N / 5; i >= 0; i--) {
            int remain = N - (i * 5);
            
            if (remain % 3 == 0) {
                result = i + (remain / 3);
                break;
            }
        }

        System.out.println(result);
        sc.close();
    }
}
