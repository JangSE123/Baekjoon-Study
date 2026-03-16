package Stage29.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Problem9370 {
    static class Edge implements Comparable<Edge> {
        int to, cost;

        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }

    static int n, m, t;
    static int s, g, h;
    static final int INF = 1000000000;
    static ArrayList<Edge>[] graph;

    static int[] dijkstra(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);

        dist[start] = 0;
        pq.add(new Edge(start, 0));

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (cur.cost > dist[cur.to]) continue;

            for (Edge next : graph[cur.to]) {
                int nd = cur.cost + next.cost;

                if (dist[next.to] > nd) {
                    dist[next.to] = nd;
                    pq.add(new Edge(next.to, nd));
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {

            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            g = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            graph = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();

            int ghCost = 0;

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());

                graph[a].add(new Edge(b, d));
                graph[b].add(new Edge(a, d));

                if ((a == g && b == h) || (a == h && b == g)) {
                    ghCost = d;
                }
            }

            int[] candidate = new int[t];
            for (int i = 0; i < t; i++) {
                candidate[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(candidate);

            int[] distS = dijkstra(s);
            int[] distG = dijkstra(g);
            int[] distH = dijkstra(h);

            for (int x : candidate) {

                int path1 = distS[g] + ghCost + distH[x];
                int path2 = distS[h] + ghCost + distG[x];

                if (distS[x] == path1 || distS[x] == path2) {
                    sb.append(x).append(" ");
                }
            }

            sb.append("\n");
        }

        System.out.print(sb);
        br.close();
    }
}