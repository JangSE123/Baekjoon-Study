package Stage8.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1193 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int X = Integer.parseInt(br.readLine());

        int line = 1;
        int count = 0;

        while (count + line < X) {
            count += line;
            line++;
        }

        int indexLine = X - count;
        int numerator, denominator;
        
        if (line % 2 == 0) {
            numerator = indexLine;
            denominator = line - indexLine + 1;
        } else {
            numerator = line - indexLine + 1;
            denominator = indexLine;
        }

        System.out.println(numerator + "/" + denominator);
        br.close();
    }
}
