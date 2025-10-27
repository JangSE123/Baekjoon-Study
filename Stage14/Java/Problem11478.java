package Stage14.Java;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem11478 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        Set<String> sub = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                sub.add(s.substring(i, j));
            }
        }

        System.out.println(sub.size());
        sc.close();
    }
}
