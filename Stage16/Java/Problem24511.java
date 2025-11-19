package Stage16.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Problem24511 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        int[] A = new int[N];
        int[] B = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) A[i] = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) B[i] = Integer.parseInt(st.nextToken());

        Deque<Integer> dq = new ArrayDeque<>();

        for (int i = N - 1; i >= 0; i--) {
            if (A[i] == 0) {
                dq.addLast(B[i]);
            }
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        while (M-- > 0) {
            int x = Integer.parseInt(st.nextToken());
            dq.addLast(x);
            sb.append(dq.pollFirst());
            if (M > 0) sb.append(" ");
        }

        System.out.println(sb);
        br.close();
    }
}
