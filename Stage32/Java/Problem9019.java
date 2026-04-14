package Stage32.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Problem9019 {
    static String bfs(int A, int B) {
        boolean[] visited = new boolean[10000];
        int[] parent = new int[10000];
        char[] command = new char[10000];

        Queue<Integer> q = new LinkedList<>();
        q.add(A);
        visited[A] = true;

        while (!q.isEmpty()) {
            int now = q.poll();

            if (now == B) break;

            int d = (now * 2) % 10000;
            if (!visited[d]) {
                visited[d] = true;
                parent[d] = now;
                command[d] = 'D';
                q.add(d);
            }

            int s = (now == 0) ? 9999 : now - 1;
            if (!visited[s]) {
                visited[s] = true;
                parent[s] = now;
                command[s] = 'S';
                q.add(s);
            }

            int l = (now % 1000) * 10 + (now / 1000);
            if (!visited[l]) {
                visited[l] = true;
                parent[l] = now;
                command[l] = 'L';
                q.add(l);
            }

            int r = (now % 10) * 1000 + (now / 10);
            if (!visited[r]) {
                visited[r] = true;
                parent[r] = now;
                command[r] = 'R';
                q.add(r);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        int cur = B;

        while (cur != A) {
            sb.append(command[cur]);
            cur = parent[cur];
        }

        return sb.reverse().toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            result.append(bfs(A, B)).append("\n");
        }

        System.out.println(result);
    }
}
