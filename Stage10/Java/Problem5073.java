package Stage10.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem5073 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int side1 = Integer.parseInt(st.nextToken());
            int side2 = Integer.parseInt(st.nextToken());
            int side3 = Integer.parseInt(st.nextToken());

            if (side1 == 0 && side2 == 0 && side3 == 0) break;
            
            int max = Math.max(side1, Math.max(side2, side3));
            int sum = side1 + side2 + side3;

            if (sum - max <= max) {
                System.out.println("Invalid");
            } else if (side1 == side2 && side2 == side3) {
                System.out.println("Equilateral");
            } else if (side1 == side2 || side2 == side3 || side1 == side3) {
                System.out.println("Isosceles");
            } else {
                System.out.println("Scalene");
            }
        }
        br.close();
    }
}
