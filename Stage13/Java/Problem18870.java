package Stage13.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Problem18870 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] sorted = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            sorted[i] = arr[i];
        }

        Arrays.sort(sorted);

        HashMap<Integer, Integer> rank = new HashMap<>();
        int idx = 0;
        for (int num : sorted) {
            if (!rank.containsKey(num)) {
                rank.put(num, idx++);
            }
        }

        for (int i = 0; i < N; i++) {
            sb.append(rank.get(arr[i])).append(" ");
        }

        System.out.println(sb);
        br.close();
    }
}
