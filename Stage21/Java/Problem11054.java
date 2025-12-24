package Stage21.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem11054 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int[] inc = new int[N];
        for (int i = 0; i < N; i++) {
            inc[i] = 1;
            for (int j = 0; j < i; j++) {
                if (A[j] < A[i]) {
                    inc[i] = Math.max(inc[i], inc[j] + 1);
                }
            }
        }
        
        int[] dec = new int[N];
        for (int i = N - 1; i >= 0; i--) {
            dec[i] = 1;
            for (int j = N - 1; j > i; j--) {
                if (A[j] < A[i]) {
                    dec[i] = Math.max(dec[i], dec[j] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = Math.max(ans, inc[i] + dec[i] - 1);
        }

        System.out.println(ans);
        br.close();
    }
}
