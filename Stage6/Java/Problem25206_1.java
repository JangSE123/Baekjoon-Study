package Stage6.Java;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Problem25206_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Map<String, Double> gradeMap = new HashMap<>();
        gradeMap.put("A+", 4.5);
        gradeMap.put("A0", 4.0);
        gradeMap.put("B+", 3.5);
        gradeMap.put("B0", 3.0);
        gradeMap.put("C+", 2.5);
        gradeMap.put("C0", 2.0);
        gradeMap.put("D+", 1.5);
        gradeMap.put("D0", 1.0);
        gradeMap.put("F", 0.0);

        double totalScore = 0.0;
        double totalCredit = 0.0;

        for (int i = 0; i < 20; i++) {
            String line = sc.nextLine();
            String[] parts = line.split(" ");
            String subject = parts[0];
            double credit = Double.parseDouble(parts[1]);
            String grade = parts[2];

            if (!grade.equals("P")) {
                totalCredit += credit;
                totalScore += credit * gradeMap.get(grade);
            }
        }

        double average = totalScore / totalCredit;

        System.out.printf("%.6f\n", average);
        sc.close();
    }
}
