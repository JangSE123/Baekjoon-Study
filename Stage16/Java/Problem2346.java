package Stage16.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Problem2346 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int N = Integer.parseInt(br.readLine());
        Deque<int[]> dq = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for (int i = 1; i <= N; i++) {
            dq.addLast(new int[]{i, Integer.parseInt(st.nextToken())});
        }

        while (!dq.isEmpty()) {
            int[] cur = dq.pollFirst();
            sb.append(cur[0]).append(" ");

            if (dq.isEmpty()) break;

            int move = cur[1];
            if (move > 0) {
                for (int i = 1; i < move; i++) {
                    dq.addLast(dq.pollFirst());
                }
            } else {
                for (int i = 0; i < -move; i++) {
                    dq.addFirst(dq.pollLast());
                }
            }
        }

        System.out.println(sb);
        br.close();
    }
}
