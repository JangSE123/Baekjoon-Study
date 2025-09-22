package Stage9.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem5086 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());

            if (X == 0 && Y == 0) break;

            if (Y % X == 0) {
                sb.append("factor\n");
            } else if (X % Y == 0) {
                sb.append("multiple\n");
            } else {
                sb.append("neither\n");
            }
        }

        System.out.print(sb);
        br.close();
    }
}
