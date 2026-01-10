package Stage23.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1541 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        String[] minus = s.split("-");

        int result = 0;

        String[] first = minus[0].split("\\+");
        for (String num : first) {
            result += Integer.parseInt(num);
        }

        for (int i = 1; i < minus.length; i++) {
            String[] plus = minus[i].split("\\+");
            int temp = 0;
            for (String num : plus) {
                temp += Integer.parseInt(num);
            }
            result -= temp;
        }

        System.out.println(result);
        br.close();
    }
}
