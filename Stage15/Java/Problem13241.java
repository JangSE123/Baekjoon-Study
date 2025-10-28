package Stage15.Java;

import java.math.BigInteger;
import java.util.Scanner;

public class Problem13241 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();

        BigInteger A = BigInteger.valueOf(a);
        BigInteger B = BigInteger.valueOf(b);

        BigInteger gcd = A.gcd(B);
        BigInteger lcm = A.multiply(B).divide(gcd);

        System.out.println(lcm);
        sc.close();
    }
}
