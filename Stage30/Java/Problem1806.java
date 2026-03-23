package Stage30.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1806 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0, end = 0;
        int sum = 0;
        int minLen = Integer.MAX_VALUE;

        while (true) {
            if (sum >= S) {
                minLen = Math.min(minLen, end - start);
                sum -= arr[start++];
            } else {
                if (end == N) break;
                sum += arr[end++];
            }
        }

        if (minLen == Integer.MAX_VALUE) System.out.println(0);
        else System.out.println(minLen);

        br.close();
    }
}
