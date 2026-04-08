package Stage32.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Problem14003 {
    static int[] arr, lis, prev, lastIdx;
    static int N;

    static int lisProcess() {
        int len = 0;

        for (int i = 0; i < N; i++) {
            int pos = Arrays.binarySearch(lis, 0, len, arr[i]);
            if (pos < 0) pos = -(pos + 1);

            lis[pos] = arr[i];
            lastIdx[pos] = i;

            prev[i] = (pos > 0) ? lastIdx[pos - 1] : -1;

            if (pos == len) len++;
        }

        return len;
    }

    static int lastIndex(int len) {
        return lastIdx[len - 1];
    }

    static String trace(int start) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stack = new Stack<>();

        while (start != -1) {
            stack.push(arr[start]);
            start = prev[start];
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }

        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        arr = new int[N];
        lis = new int[N];
        prev = new int[N];
        lastIdx = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int len = lisProcess();
        int last = lastIndex(len);

        String result = trace(last);

        System.out.println(len);
        System.out.println(result);
        br.close();
    }
}
