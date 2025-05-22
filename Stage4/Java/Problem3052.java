package Stage4.Java;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem3052 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Set<Integer> mod = new HashSet<>();

        int B = 42;

        for (int i = 0; i < 10; i++) {
            int A = sc.nextInt();
            mod.add(A % B);
        }

        System.out.println(mod.size());

        sc.close();
    }
}