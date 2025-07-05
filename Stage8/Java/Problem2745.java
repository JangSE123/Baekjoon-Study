package Stage8.Java;

import java.util.Scanner;

public class Problem2745 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String N = sc.next().toUpperCase();
        int B = sc.nextInt();

        int result = 0;
        int power = 1;

        for (int i = N.length() - 1; i >= 0; i--) {
            char c = N.charAt(i);
            int value;

            if (c >= '0' && c <= '9') {
                value = c - '0';
            } else {
                value = c - 'A' + 10;
            }

            result += value * power;
            power *= B;
        }

        System.out.println(result);
        sc.close();
    }
}
