package Stage21.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1912 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int max = arr[0];
        int cur = arr[0];

        for (int i = 1; i < n; i++) {
            cur = Math.max(arr[i], cur + arr[i]);
            max = Math.max(max, cur);
        }

        System.out.println(max);
        br.close();
    }
}
