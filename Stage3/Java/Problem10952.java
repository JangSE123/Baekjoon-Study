package Stage3.Java;

import java.util.Scanner;

public class Problem10952 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        
        while (true) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            if (A == 0 && B == 0) {
                break;
            }

            sb.append(A + B + "\n");
        }

        System.out.println(sb);
        sc.close();
    }
}
