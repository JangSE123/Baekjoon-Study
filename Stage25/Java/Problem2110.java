package Stage25.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem2110 {
    static int N, C;
    static int[] house;

    static int binarySearch() {
        int left = 1;
        int right = house[N - 1] - house[0];
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canInstall(mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

    static boolean canInstall(int dist) {
        int count = 1;
        int last = house[0];

        for (int i = 1; i < N; i++) {
            if (house[i] - last >= dist) {
                count++;
                last = house[i];
            }
        }

        return count >= C;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        house = new int[N];
        for (int i = 0; i < N; i++) {
            house[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(house);
        System.out.println(binarySearch());
    }
}
