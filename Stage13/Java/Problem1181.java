package Stage13.Java;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Problem1181 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();

        Set<String> set = new HashSet<>();

        for (int i = 0; i < N; i++) {
            set.add(sc.nextLine());
        }

        List<String> words = new ArrayList<>(set);

        words.sort((a, b) -> {
            if (a.length() != b.length()) return a.length() - b.length();
            return a.compareTo(b);
        });

        for (String w : words) {
            System.out.println(w);
        }

        sc.close();
    }
}
