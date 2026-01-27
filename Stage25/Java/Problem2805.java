package Stage25.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long M = Long.parseLong(st.nextToken());

        long[] tree = new long[N];
        st = new StringTokenizer(br.readLine());

        long max = 0;
        for (int i = 0; i < N; i++) {
            tree[i] = Long.parseLong(st.nextToken());
            max = Math.max(max, tree[i]);
        }

        long left = 0;
        long right = max;
        long answer = 0;

        while (left <= right) {
            long mid = (left + right) / 2;

            long total = 0;
            for (long h : tree) {
                if (h > mid) {
                    total += h - mid;
                }
            }

            if (total >= M) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(answer);
        br.close();
    }
}
