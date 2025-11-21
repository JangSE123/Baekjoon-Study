package Stage17.Java;

import java.util.Scanner;

public class Problem24723 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int result = 1 << N;

        System.out.println(result);
        sc.close();
    }
}
