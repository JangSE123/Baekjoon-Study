package Stage18.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem2108 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N];
        int[] freq = new int[8001];
        int sum = 0;

        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(br.readLine());
            arr[i] = x;
            sum += x;
            freq[x + 4000]++;
        }

        int avg = (int) Math.round((double) sum / N);

        Arrays.sort(arr);
        int mid = arr[N / 2];

        int maxFreq = 0;
        for (int f : freq) maxFreq = Math.max(maxFreq, f);

        int mode = 0;
        int countFreq = 0;
        for (int i = 0; i < 8001; i++) {
            if (freq[i] == maxFreq) {
                mode = i - 4000;
                countFreq++;
                if (countFreq == 2) break;
            }
        }

        int range = arr[N - 1] - arr[0];

        sb.append(avg).append("\n");
        sb.append(mid).append("\n");
        sb.append(mode).append("\n");
        sb.append(range);

        System.out.println(sb);
        br.close();
    }
}
