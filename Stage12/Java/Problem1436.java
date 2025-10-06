package Stage12.Java;

import java.util.Scanner;

public class Problem1436 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int num = 666;
        int count = 0;

        while (true) {
            if (String.valueOf(num).contains("666")) {
                count++;
            }

            if (count == N) {
                System.out.println(num);
                break;
            }
            num++;
        }
        
        sc.close();
    }
}
