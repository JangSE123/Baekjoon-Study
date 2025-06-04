package Stage5.Java;

import java.util.Scanner;

public class Problem2908 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String A = sc.next();
        String B = sc.next();

        int revA = Integer.parseInt(new StringBuilder(A).reverse().toString());
        int revB = Integer.parseInt(new StringBuilder(B).reverse().toString());

        System.out.println(Math.max(revA, revB));
        sc.close();
    }
}
