package Stage25.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem12015 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] lis = new int[N];
        int size = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(st.nextToken());

            int left = 0;
            int right = size;

            while (left < right) {
                int mid = (left + right) / 2;
                if (lis[mid] < x) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            lis[left] = x;

            if (left == size) {
                size++;
            }
        }

        System.out.println(size);
        br.close();
    }
}
