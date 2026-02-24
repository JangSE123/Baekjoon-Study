package Stage27.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Problem1697 {
    static int N, K;
    static boolean[] visited = new boolean[100001];

    static int bfs() {
        if (N == K) return 0;

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{N, 0});
        visited[N] = true;

        while(true) {
            int[] cur = queue.poll();
            int x = cur[0];
            int time = cur[1];

            if (x == K) return time;

            if (x - 1 >= 0 && !visited[x - 1]) {
                visited[x - 1] = true;
                queue.offer(new int[]{x - 1, time + 1});
            }

            if (x + 1 <= 100000 && !visited[x + 1]) {
                visited[x + 1] = true;
                queue.offer(new int[]{x + 1, time + 1});
            }

            if (x * 2 <= 100000 && !visited[x * 2]) {
                visited[x * 2] = true;
                queue.offer(new int[]{x * 2, time + 1});
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        System.out.println(bfs());
    }
}
