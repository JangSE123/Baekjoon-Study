package Stage15.Java;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Problem2485_1 {
    static int getGCD(int a, int b) {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        List<Integer> trees = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            trees.add(sc.nextInt());
        }

        List<Integer> distances = new ArrayList<>();
        for (int i = 0; i < N - 1; i++) {
            distances.add(trees.get(i + 1) - trees.get(i));
        }

        int gcd = distances.get(0);
        for (int i = 1; i < distances.size(); i++) {
            gcd = getGCD(gcd, distances.get(i));
        }

        int total = (trees.get(N - 1) - trees.get(0)) / gcd + 1;
        System.out.println(total - N);
        sc.close();
    }
}
