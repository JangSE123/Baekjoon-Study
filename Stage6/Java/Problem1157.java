package Stage6.Java;

import java.util.Scanner;

public class Problem1157 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word = sc.nextLine().toUpperCase();
        int[] alphabet = new int[26];
        
        for (int i = 0; i < word.length(); i++) {
            alphabet[word.charAt(i) - 'A']++;
        }

        int maxValue = 0;
        char result = '?';
        
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] > maxValue) {
                maxValue = alphabet[i];
                result = (char)(i + 'A');
            } else if (alphabet[i] == maxValue) {
                result = '?';
            }
        }

        System.out.println(result);
        sc.close();
    }
}