package Stage26.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Problem1202 {
    static class Jewel {
        int mass;
        int value;

        Jewel(int M, int V) {
            this.mass = M;
            this.value = V;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Jewel[] jewels = new Jewel[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            jewels[i] = new Jewel(M, V);
        }

        Arrays.sort(jewels, (a, b) -> a.mass - b.mass);
        
        int[] bags = new int[K];
        for (int i = 0; i < K; i++) {
            int C = Integer.parseInt(br.readLine());
            bags[i] = C;
        }

        Arrays.sort(bags);

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        long total = 0;
        int idx = 0;

        for (int bag : bags) {
            while (idx < N && jewels[idx].mass <= bag) {
                pq.add(jewels[idx].value);
                idx++;
            }

            if (!pq.isEmpty()) {
                total += pq.poll();
            }
        }

        System.out.println(total);
        br.close();
    }
}
