package Stage5.Java;

import java.util.Scanner;

public class Problem1152 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();

        if (text.trim().isEmpty()) {
            System.out.println(0);
        } else {
            String[] words = text.trim().split(" ");
            System.out.println(words.length);
        }

        sc.close();
    }
}
