package Stage19.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem24060 {
    static int[] A, tmp;
    static int K, count = 0, result = -1;

    public static void mergeSort(int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    public static void merge(int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int t = left;

        while (i <= mid && j <= right) {
            if (A[i] <= A[j]) tmp[t++] = A[i++];
            else tmp[t++] = A[j++];
            count++;
            if (count == K) result = tmp[t - 1];
        }

        while (i <= mid) {
            tmp[t++] = A[i++];
            count++;
            if (count == K) result = tmp[t - 1];
        }

        while (j <= right) {
            tmp[t++] = A[j++];
            count++;
            if (count == K) result = tmp[t - 1];
        }

        for (int x = left; x <= right; x++)
            A[x] = tmp[x];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        A = new int[N];
        tmp = new int[N];

        st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        mergeSort(0, N - 1);
        
        System.out.println(result);
        br.close();
    }
}
