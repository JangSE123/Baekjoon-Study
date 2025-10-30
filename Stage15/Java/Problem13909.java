package Stage15.Java;

import java.util.Scanner;

public class Problem13909 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int result = (int)Math.sqrt(N);
        System.out.println(result);
        
        sc.close();
    }
}
