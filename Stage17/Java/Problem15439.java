package Stage17.Java;

import java.util.Scanner;

public class Problem15439 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int result = N * (N - 1);

        System.out.println(result);
        sc.close();
    }
}
