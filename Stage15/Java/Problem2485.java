package Stage15.Java;

import java.util.Scanner;

public class Problem2485 {
    static int getGCD(int a, int b) {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] trees = new int[N];
        for (int i = 0; i < N; i++) {
            trees[i] = sc.nextInt();
        }

        int[] distances = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            distances[i] = trees[i + 1] - trees[i];
        }

        int gcd = distances[0];
        for (int i = 1; i < distances.length; i++) {
            gcd = getGCD(gcd, distances[i]);
        }

        int total = (trees[N - 1] - trees[0]) / gcd + 1;
        System.out.println(total - N);
        sc.close();
    }
}
