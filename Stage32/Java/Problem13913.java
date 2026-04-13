package Stage32.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Problem13913 {
    static final int MAX = 100001;
    static int[] dist = new int[MAX];
    static int[] prev = new int[MAX];

    static void bfs(int start, int target) {
        Arrays.fill(dist, -1);

        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        dist[start] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == target) return;

            int[] next = {cur - 1, cur + 1, cur * 2};

            for (int nx : next) {
                if (nx >= 0 && nx < MAX && dist[nx] == -1) {
                    dist[nx] = dist[cur] + 1;
                    prev[nx] = cur;
                    q.offer(nx);
                }
            }
        }
    }

    static void printPath(int start, int target) {
        Stack<Integer> stack = new Stack<>();
        int cur = target;

        while (cur != start) {
            stack.push(cur);
            cur = prev[cur];
        }
        stack.push(start);

        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        bfs(N, K);

        System.out.println(dist[K]);
        printPath(N, K);
    }
}
