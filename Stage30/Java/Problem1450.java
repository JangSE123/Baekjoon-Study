package Stage30.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Problem1450 {
    static int N, C;
    static int[] arr;
    static ArrayList<Integer> left = new ArrayList<>();
    static ArrayList<Integer> right = new ArrayList<>();
    
    static void dfs(int start, int end, int sum, ArrayList<Integer> list) {
        if (sum > C) return;

        if (start == end) {
            list.add(sum);
            return;
        }

        dfs(start + 1, end, sum, list);

        dfs(start + 1, end, sum + arr[start], list);
    }

    static int upperBound(ArrayList<Integer> list, int target) {
        int left = 0;
        int right = list.size();

        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid) <= target) left = mid + 1;
            else right = mid;
        }

        return left;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, N / 2, 0, left);
        dfs(N / 2, N, 0, right);

        Collections.sort(right);

        long count = 0;

        for (int l : left) {
            if (l > C) continue;

            int remain = C - l;

            int idx = upperBound(right, remain);
            count += idx;
        }

        System.out.println(count);
        br.close();
    }
}
