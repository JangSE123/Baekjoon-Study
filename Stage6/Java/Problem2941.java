package Stage6.Java;

import java.util.Scanner;

public class Problem2941 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word = sc.nextLine();
        String[] croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

        for (String str : croatia) {
            word = word.replace(str, "*");
        }

        System.out.println(word.length());
        sc.close();
    }
}
