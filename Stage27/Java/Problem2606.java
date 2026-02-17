package Stage27.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Problem2606 {
    static int com, line;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static int count = 0;

    static void dfs(int start) {
        visited[start] = true;

        for (int next : graph[start]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        com = Integer.parseInt(br.readLine());
        line = Integer.parseInt(br.readLine());
        
        graph = new ArrayList[com + 1];
        visited = new boolean[com + 1];

        for (int i = 1; i <= com; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < line; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a].add(b);
            graph[b].add(a);
        }

        dfs(1);

        for (int i = 2; i <= com; i++) {
            if (visited[i]) count++;
        }

        System.out.println(count);
        br.close();
    }
}
