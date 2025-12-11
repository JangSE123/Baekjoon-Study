package Stage20.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem14888 {
    static int N;
    static int[] nums;
    static int[] op = new int[4];
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    static void dfs(int idx, int current) {
        if (idx == N) {
            max = Math.max(max, current);
            min = Math.min(min, current);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (op[i] > 0) {
                op[i]--;

                if (i == 0) dfs(idx + 1, current + nums[idx]);
                else if (i == 1) dfs(idx + 1, current - nums[idx]);
                else if (i == 2) dfs(idx + 1, current * nums[idx]);
                else dfs(idx + 1, current / nums[idx]);

                op[i]++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        nums = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) nums[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) op[i] = Integer.parseInt(st.nextToken());

        dfs(1, nums[0]);

        System.out.println(max);
        System.out.println(min);
        br.close();
    }
}
