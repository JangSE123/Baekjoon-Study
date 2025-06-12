package Stage6.Java;

import java.util.Scanner;

public class Problem1316 {
    public static boolean isGroupWord(String word) {
        boolean[] used = new boolean[26];
        char prev = word.charAt(0);
        used[prev - 'a'] = true;

        for (int i = 1; i < word.length(); i++) {
            char curr = word.charAt(i);

            if (prev != curr) {

                if (used[curr - 'a']) {
                    return false;
                }

                used[curr - 'a'] = true;
            }

            prev = curr;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        sc.nextLine();
        int count = 0;

        for (int i = 0; i < N; i++) {
            String word = sc.nextLine();

            if (isGroupWord(word)) {
                count++;
            }

        }

        System.out.println(count);
        sc.close();
    }
}
