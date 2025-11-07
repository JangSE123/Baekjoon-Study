package Stage16.Java;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Problem10773 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();

        Deque<Integer> deque = new ArrayDeque<>();

        while (K-- > 0) {
            int num = sc.nextInt();
            if (num == 0) deque.pop();
            else deque.push(num);
        }

        int result = 0;

        for (int d : deque) result += d;

        System.out.println(result);
        sc.close();
    }
}
