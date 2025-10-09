package Stage13.Java;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Problem1427_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N = sc.nextLine();

        Character[] arr = new Character[N.length()];
        for (int i = 0; i < N.length(); i++) {
            arr[i] = N.charAt(i);
        }

        Arrays.sort(arr, Collections.reverseOrder());

        for (char c : arr) {
            System.out.print(c);
        }

        sc.close();
    }
}
