package Stage16.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Problem12789 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        Queue<Integer> queue = new LinkedList<>();
        
        for (int i = 0; i < N; i++) {
            queue.add(Integer.parseInt(st.nextToken()));
        }

        Stack<Integer> stack = new Stack<>();
        int cur = 1;

        while (!queue.isEmpty()) {
            int now = queue.peek();

            if (now == cur) {
                queue.poll();
                cur++;
            } else if (!stack.isEmpty() && stack.peek() == cur) {
                stack.pop();
                cur++;
            } else {
                stack.push(queue.poll());
            }
        }

        while (!stack.isEmpty() && stack.peek() == cur) {
            stack.pop();
            cur++;
        }

        if (cur == N + 1) System.out.println("Nice");
        else System.out.println("Sad");
    }
}
