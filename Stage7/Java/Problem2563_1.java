package Stage7.Java;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem2563_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        Set<String> covered = new HashSet<>();

        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();

            for (int j = x; j < x + 10; j++) {
                for (int k = y; k < y + 10; k++) {
                    covered.add((j) + "," + (k));
                }
            }
            
        }

        System.out.println(covered.size());
        sc.close();
    }
}
