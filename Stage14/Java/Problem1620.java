package Stage14.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Problem1620 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> nameToNum = new HashMap<>();
        String[] numToName = new String[N + 1];

        for (int i = 1; i <= N; i++) {
            String name = br.readLine();
            nameToNum.put(name, i);
            numToName[i] = name;
        }

        for (int i = 0; i < M; i++) {
            String q = br.readLine();
            if (Character.isDigit(q.charAt(0))) {
                int num = Integer.parseInt(q);
                sb.append(numToName[num]).append('\n');
            } else {
                sb.append(nameToNum.get(q)).append('\n');
            }
        }

        System.out.print(sb);
        br.close();
    }
}
