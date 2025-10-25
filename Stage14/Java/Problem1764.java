package Stage14.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Problem1764 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        String[] listen = new String[N];
        for (int i = 0; i < N; i++) {
            listen[i] = br.readLine();
        }

        String[] see = new String[M];
        for (int i = 0; i < M; i++) {
            see[i] = br.readLine();
        }

        Arrays.sort(see);

        List<String> common = new ArrayList<>();
        for (String name : listen) {
            if (Arrays.binarySearch(see, name) >= 0) {
                common.add(name);
            }
        }

        Collections.sort(common);

        System.out.println(common.size());
        for (String name : common) {
            System.out.println(name);
        }
    }
}
