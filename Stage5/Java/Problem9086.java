package Stage5.Java;

import java.util.Scanner;

public class Problem9086 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < T; i++) {
            String str = sc.nextLine();
            sb.append(str.charAt(0)).append(str.charAt(str.length() - 1)).append("\n");
        }

        System.out.println(sb);
        sc.close();
    }
}
