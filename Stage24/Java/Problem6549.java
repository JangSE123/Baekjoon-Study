package Stage24.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Problem6549 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String line = br.readLine();
            if (line.equals("0")) break;

            StringTokenizer st = new StringTokenizer(line);
            int n = Integer.parseInt(st.nextToken());
    
            long[] h = new long[n];
            for (int i = 0; i < n; i++) {
                h[i] = Long.parseLong(st.nextToken());
            }

            Stack<Integer> stack = new Stack<>();
            long max = 0;

            for (int i = 0; i < n; i++) {
                while(!stack.isEmpty() && h[stack.peek()] > h[i]) {
                    int heightIdx = stack.pop();
                    long height = h[heightIdx];

                    int width;
                    if (stack.isEmpty()) {
                        width = i;
                    } else {
                        width = i - stack.peek() - 1;
                    }

                    max = Math.max(max, height * width);
                }
                stack.push(i);
            }

            while (!stack.isEmpty()) {
                int heightIdx = stack.pop();
                long height = h[heightIdx];

                int width;
                if (stack.isEmpty()) {
                    width = n;
                } else {
                    width = n - stack.peek() - 1;
                }

                max = Math.max(max, height * width);
            }

            sb.append(max).append('\n');
        }

        System.out.println(sb);
        br.close();
    }
}
