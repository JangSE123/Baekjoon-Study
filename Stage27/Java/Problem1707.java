package Stage27.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Problem1707 {
    static ArrayList<Integer>[] graph;
    static int[] color;
    static boolean isBipartite;

    static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        color[start] = 1;

        while (!queue.isEmpty()) {
            int cur = queue.poll();

            for (int next : graph[cur]) {
                if (color[next] == 0) {
                    color[next] = -color[cur];
                    queue.offer(next);
                } 
                else if (color[next] == color[cur]) {
                    isBipartite = false;
                    return;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int K = Integer.parseInt(br.readLine());

        while (K-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int V = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());

            graph = new ArrayList[V + 1];
            color = new int[V + 1];
            isBipartite = true;

            for (int i = 1; i <= V; i++) {
                graph[i] = new ArrayList<>();
            }

            for (int i = 0; i < E; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                graph[u].add(v);
                graph[v].add(u);
            }

            for (int i = 1; i <= V; i++) {
                if (color[i] == 0) {
                    bfs(i);
                }
                if (!isBipartite) break;
            }

            sb.append(isBipartite ? "YES\n" : "NO\n");
        }

        System.out.print(sb);
    }
}
