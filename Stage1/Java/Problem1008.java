package Stage1.Java;

import java.util.Scanner;

public class Problem1008 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();

        double result = (double) A / B;

        System.out.println(result);

        sc.close();
    }
}
