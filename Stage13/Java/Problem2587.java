package Stage13.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem2587 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[5];
        
        for (int i = 0; i < 5; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        
        Arrays.sort(arr);

        int sum = 0;

        for (int num : arr) {
            sum += num;
        }

        int avg = sum / 5;
        int median = arr[2];

        System.out.println(avg);
        System.out.println(median);
        br.close();
    }
}
