package Stage16.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Problem28279 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        Deque<Integer> dq = new ArrayDeque<>();

        while (N-- > 0) {
            String[] input = br.readLine().split(" ");
            int command = Integer.parseInt(input[0]);

            switch (command) {
                case 1:
                    int X1 = Integer.parseInt(input[1]);
                    dq.addFirst(X1);
                    break;
                case 2:
                    int X2 = Integer.parseInt(input[1]);
                    dq.addLast(X2);
                    break;
                case 3:
                    sb.append(dq.isEmpty() ? -1 : dq.pollFirst()).append("\n");
                    break;
                case 4:
                    sb.append(dq.isEmpty() ? -1 : dq.pollLast()).append("\n");
                    break;
                case 5:
                    sb.append(dq.size()).append("\n");
                    break;
                case 6:
                    sb.append(dq.isEmpty() ? 1 : 0).append("\n");
                    break;
                case 7:
                    sb.append(dq.isEmpty() ? -1 : dq.peekFirst()).append("\n");
                    break;
                case 8:
                    sb.append(dq.isEmpty() ? -1 : dq.peekLast()).append("\n");
                    break;
            }
        }

        System.out.println(sb);
        br.close();
    }
}
