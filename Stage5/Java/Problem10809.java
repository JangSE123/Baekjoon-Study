package Stage5.Java;

import java.util.Scanner;

public class Problem10809 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int[] alphabet = new int[26];

        for (int i = 0; i < 26; i++) {
            alphabet[i] = -1;
        }

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            int index = c - 'a';
            if (alphabet[index] == -1) alphabet[index] = i;     
        }

        for (int num : alphabet) System.out.print(num + " ");

        sc.close();
    }
}
