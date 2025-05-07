package Stage2.Java;

import java.util.Scanner;

public class Problem2753 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int year = sc.nextInt();

        boolean leapYear = (year % 4 ==0 && year % 100 != 0) || (year % 400 == 0);

        System.out.println(leapYear ? 1 : 0);

        sc.close();
    }
}
