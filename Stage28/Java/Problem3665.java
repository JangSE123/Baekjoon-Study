package Stage28.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Problem3665 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());

            int[] indegree = new int[n + 1];
            boolean[][] graph = new boolean[n + 1][n + 1];

            int[] rank = new int[n];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) rank[i] = Integer.parseInt(st.nextToken());

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    graph[rank[i]][rank[j]] = true;
                    indegree[rank[j]]++;
                }
            }

            int m = Integer.parseInt(br.readLine());

            while (m-- > 0) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                if (graph[a][b]) {
                    graph[a][b] = false;
                    graph[b][a] = true;
                    indegree[b]--;
                    indegree[a]++;
                } else {
                    graph[b][a] = false;
                    graph[a][b] = true;
                    indegree[a]--;
                    indegree[b]++;
                }
            }

            Queue<Integer> q = new LinkedList<>();

            for (int i = 1; i <= n; i++) {
                if (indegree[i] == 0) q.offer(i);
            }

            List<Integer> result = new ArrayList<>();
            boolean uncertain = false;

            for (int i = 0; i < n; i++) {
                if (q.isEmpty()) {
                    sb.append("IMPOSSIBLE\n");
                    uncertain = true;
                    break;
                }

                if (q.size() > 1) uncertain = true;

                int now = q.poll();
                result.add(now);

                for (int j = 1; j <= n; j++) {
                    if (graph[now][j]) {
                        indegree[j]--;
                        if (indegree[j] == 0) q.offer(j);
                    }
                }
            }

            if (!uncertain) {
                for (int x : result) sb.append(x).append(" ");
                sb.append("\n");
            } else if (!q.isEmpty()) {
                sb.append("?\n");
            }
        }

        System.out.println(sb);
        br.close();
    }
}
