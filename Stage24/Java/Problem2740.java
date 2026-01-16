package Stage24.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2740 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M1 = Integer.parseInt(st.nextToken());

        int[][] A = new int[N][M1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M1; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        int M2 = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] B = new int[M2][K];
        for (int i = 0; i < M2; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < K; j++) {
                B[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                int sum = 0;
                for (int t = 0; t < M1; t++) {
                    sum += A[i][t] * B[t][j];
                }
                sb.append(sum).append(' ');
            }
            sb.append('\n');
        }

        System.out.println(sb);
        br.close();
    }
}
