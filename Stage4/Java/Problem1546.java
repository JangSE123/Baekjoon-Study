package Stage4.Java;

import java.util.Scanner;

public class Problem1546 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double M = 0;
        double[] scores = new double[N];

        for (int i = 0; i < N; i++) {
            scores[i] = sc.nextDouble();
            if (scores[i] > M) M = scores[i];
        }

        double sum = 0;
        
        for (double s : scores) {
            sum += (s / M) * 100;
        }

        System.out.println(sum / N);
        sc.close();
    }
}
