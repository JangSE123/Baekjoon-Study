package Stage13.Java;

import java.util.Arrays;
import java.util.Scanner;

public class Problem1427 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N = sc.nextLine();

        char[] arr = N.toCharArray();
        Arrays.sort(arr);

        for (int i = arr.length - 1; i >= 0; i--) {
            System.out.print(arr[i]);
        }

        sc.close();
    }
}
