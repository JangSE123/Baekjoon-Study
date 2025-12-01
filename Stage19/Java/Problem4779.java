package Stage19.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4779 {
    static char[] arr;

    public static void cantor(int start, int size) {
        if (size == 1) return;

        int len = size / 3;

        for (int i = start + len; i < start + len * 2; i++) {
            arr[i] = ' ';
        }

        cantor(start, len);
        cantor(start + len * 2, len);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String input;

        while ((input = br.readLine()) != null) {
            int N = Integer.parseInt(input);
            int size = (int) Math.pow(3, N);
            arr = new char[size];

            for (int i = 0; i < size; i++) {
                arr[i] = '-';
            }

            cantor(0, size);

            sb.append(arr).append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}
