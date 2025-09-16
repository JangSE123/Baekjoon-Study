package Stage8.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Problem11005 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        ArrayList<Character> list = new ArrayList<>();

        while (N > 0) {
            if (N % B < 10) {
                list.add((char) (N % B + '0'));
            } else {
                list.add((char) (N % B - 10 + 'A'));
            }
            N /= B;
        }

        for (int i = list.size() - 1; i >= 0; i--) {
            System.out.print(list.get(i));
        }

        br.close();
    }
}
