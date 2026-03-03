package Stage27.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Problem7569 {
    static int N, M, H;
    static int[][][] box;
    static Queue<int[]> queue = new LinkedList<>();
    
    static int[] dx = {1, -1, 0, 0, 0, 0};
    static int[] dy = {0, 0, 1, -1, 0, 0};
    static int[] dz = {0, 0, 0, 0, 1, -1};

    static void bfs() {
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int z = cur[0];
            int y = cur[1];
            int x = cur[2];

            for (int i = 0; i < 6; i++) {
                int nz = z + dz[i];
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nz >= 0 && ny >= 0 && nx >= 0 && nz < H && ny < N && nx < M) {
                    if (box[nz][ny][nx] == 0) {
                        box[nz][ny][nx] = box[z][y][x] + 1;
                        queue.offer(new int[]{nz, ny, nx});
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        box = new int[H][N][M];

        for (int h = 0; h < H; h++) {
            for (int n = 0; n < N; n++) {
                st = new StringTokenizer(br.readLine());
                for (int m = 0; m < M; m++) {
                    box[h][n][m] = Integer.parseInt(st.nextToken());
                    if (box[h][n][m] == 1) {
                        queue.offer(new int[]{h, n, m});
                    }
                }
            }
        }

        bfs();

        int max = 0;

        for (int h = 0; h < H; h++) {
            for (int n = 0; n < N; n++) {
                for (int m = 0; m < M; m++) {
                    if (box[h][n][m] == 0) {
                        System.out.println(-1);
                        return;
                    }
                    max = Math.max(max, box[h][n][m]);
                }
            }
        }

        System.out.println(max - 1);
        br.close();
    }
}
