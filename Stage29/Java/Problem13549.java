package Stage29.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class Problem13549 {
    static final int MAX = 100001;
    static int[] dist = new int[MAX];

    static int bfs(int start, int target) {
        Deque<Integer> dq = new ArrayDeque<>();

        dq.add(start);
        dist[start] = 0;

        while (!dq.isEmpty()) {
            int cur = dq.pollFirst();

            if (cur == target) {
                return dist[cur];
            }

            int next = cur * 2;
            if (next < MAX && dist[next] > dist[cur]) {
                dist[next] = dist[cur];
                dq.addFirst(next);
            }

            next = cur - 1;
            if (next >= 0 && dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                dq.addLast(next);
            }

            next = cur + 1;
            if (next < MAX && dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                dq.addLast(next);
            }
        }
        
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Arrays.fill(dist, Integer.MAX_VALUE);

        int result = bfs(N, K);

        System.out.println(result);
        br.close();
    }
}
