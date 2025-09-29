package Stage11.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem24313 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a1 = Integer.parseInt(st.nextToken());
        int a0 = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(br.readLine());
        int n0 = Integer.parseInt(br.readLine());
           
        if (a1 > c) {
            System.out.println(0);
        } else if (a1 == c) {
            if (a0 <= 0) System.out.println(1);
            else System.out.println(0);
        } else {
            if (n0 >= (double)a0 / (c - a1)) System.out.println(1);
            else System.out.println(0);
        }

        br.close();
    }
}
