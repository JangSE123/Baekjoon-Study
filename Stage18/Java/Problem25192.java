package Stage18.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Problem25192 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Set<String> group = new HashSet<>();
        int count = 0;

        for (int i = 0; i < N; i++) {
            String name = br.readLine();

            if (name.equals("ENTER")) {
                group.clear();
            } else {
                if (!group.contains(name)) {
                    group.add(name);
                    count++;
                }
            }
        }

        System.out.println(count);
        br.close();
    }
}
