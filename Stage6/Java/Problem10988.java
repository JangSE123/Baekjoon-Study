package Stage6.Java;

import java.util.Scanner;

public class Problem10988 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word = sc.nextLine();
        int len = word.length();
        int isSame = 1;

        for (int i = 0; i < len / 2; i++) {
            if (word.charAt(i) != word.charAt(len - 1 - i)) isSame = 0;
        }

        System.out.println(isSame);
        sc.close();
    }
}
