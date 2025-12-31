package Stage22.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem16139 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String S = br.readLine();
        int n = S.length();

        int[][] prefix = new int[26][n];

        for (int i = 0; i < n; i++) {
            int c = S.charAt(i) - 'a';

            for (int j = 0; j < 26; j++) {
                prefix[j][i] = (i > 0) ? prefix[j][i - 1] : 0;
            }
            prefix[c][i]++;
        }
        
        int q = Integer.parseInt(br.readLine());

        for (int i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char ch = st.nextToken().charAt(0);

            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            int idx = ch - 'a';

            if (l == 0) {
                sb.append(prefix[idx][r]);
            } else {
                sb.append(prefix[idx][r] - prefix[idx][l - 1]);
            }

            sb.append('\n');
        }

        System.out.println(sb);
        br.close();
    }
}
