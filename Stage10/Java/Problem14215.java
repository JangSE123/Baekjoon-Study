package Stage10.Java;

import java.util.Arrays;
import java.util.Scanner;

public class Problem14215 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] sides = new int[3];
        sides[0] = sc.nextInt();
        sides[1] = sc.nextInt();
        sides[2] = sc.nextInt();

        Arrays.sort(sides);
        int x = sides[0], y = sides[1], z = sides[2];

        if (x + y > z) System.out.println(x + y + z);
        else System.out.println(2 * (x + y) - 1);

        sc.close();
    }
}
