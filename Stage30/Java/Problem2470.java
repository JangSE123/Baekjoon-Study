package Stage30.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem2470 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(arr);
        
        int left = 0;
        int right = N - 1;
        
        int ansL = arr[left];
        int ansR = arr[right];
        long min = Long.MAX_VALUE;
        
        while (left < right) {
            long sum = (long) arr[left] + arr[right];
            
            if (Math.abs(sum) < min) {
                min = Math.abs(sum);
                ansL = arr[left];
                ansR = arr[right];
            }
            
            if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }

        sb.append(ansL).append(" ").append(ansR);
        System.out.println(sb);
        br.close();
    }
}
