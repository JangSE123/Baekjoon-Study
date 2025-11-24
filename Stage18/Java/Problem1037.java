package Stage18.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1037 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        long min = Long.MAX_VALUE;
        long max = Long.MIN_VALUE;

        for (int i = 0; i < N; i++) {
            long d = Long.parseLong(st.nextToken());
            if (d < min) min = d;
            if (d > max) max = d;
        }

        long result;
        if (N == 1) result = min * min;
        else result = min * max;

        System.out.println(result);
        br.close();
    }
}
