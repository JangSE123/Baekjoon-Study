package Stage23.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem13305 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());

        long[] dist = new long[N - 1];
        long[] price = new long[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N - 1; i++) {
            dist[i] = Long.parseLong(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            price[i] = Long.parseLong(st.nextToken());
        }

        long minPrice = price[0];
        long cost = 0;

        for (int i = 0; i < N - 1; i++) {
            minPrice = Math.min(minPrice, price[i]);
            cost += minPrice * dist[i];
        }

        System.out.println(cost);
        br.close();
    }
}
