package Stage29.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem11657 {
    static class Edge {
        int from, to, cost;

        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    static final long INF = Long.MAX_VALUE;
    static int N, M;
    static ArrayList<Edge> edges = new ArrayList<>();
    static long[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new long[N + 1];
        Arrays.fill(dist, INF);

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            edges.add(new Edge(A, B, C));
        }

        dist[1] = 0;

        for (int i = 1; i < N; i++) {
            for (Edge e : edges) {
                if (dist[e.from] == INF) continue;

                if (dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }

        for (Edge e : edges) {
            if (dist[e.from] == INF) continue;

            if (dist[e.to] > dist[e.from] + e.cost) {
                System.out.println(-1);
                return;
            }
        }

        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                System.out.println(-1);
            } else {
                System.out.println(dist[i]);
            }
        }

        br.close();
    }
}
