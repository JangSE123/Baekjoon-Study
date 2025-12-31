package Stage22.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem10986 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        long[] count = new long[M];
        long sum = 0;
        long answer = 0;

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            sum += Long.parseLong(st.nextToken());
            int mod = (int)(sum % M);

            if (mod == 0) answer++;

            count[mod]++;
        }

        for (int i = 0; i < M; i++) {
            if (count[i] >= 2) answer += count[i] * (count[i] - 1) / 2;
        }

        System.out.println(answer);
        br.close();
    }
}
