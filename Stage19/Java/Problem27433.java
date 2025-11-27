package Stage19.Java;

import java.util.Scanner;

public class Problem27433 {
    public static long factorial(long n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        
        System.out.println(factorial(N));
        sc.close();
    }
}
