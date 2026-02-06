package Stage26.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Problem2696 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int M = Integer.parseInt(br.readLine());

            PriorityQueue<Integer> left = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Integer> right = new PriorityQueue<>();

            sb.append((M + 1) / 2).append("\n");

            int count = 0;
            int printed = 0;

            while (count < M) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                
                while (st.hasMoreTokens()) {
                    int x = Integer.parseInt(st.nextToken());
                    count++;
    
                    if (left.isEmpty() || x <= left.peek()) {
                        left.offer(x);
                    } else {
                        right.offer(x);
                    }
    
                    if (left.size() > right.size() + 1) {
                        right.offer(left.poll());
                    } else if (right.size() > left.size()) {
                        left.offer(right.poll());
                    }
    
                    if (count % 2 == 1) {
                        sb.append(left.peek()).append(" ");
                        printed++;
    
                        if (printed % 10 == 0) {
                            sb.append("\n");
                        }
                    }
    
                    if (count == M) break;
                }
            }

            sb.append("\n");
        }
        
        System.out.println(sb);
        br.close();
    }
}
