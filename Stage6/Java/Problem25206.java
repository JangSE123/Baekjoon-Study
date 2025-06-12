package Stage6.Java;

import java.util.Scanner;

public class Problem25206 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double totalCredit = 0.0;
        double totalScore = 0.0;

        for (int i = 0; i < 20; i++) {
            String line = sc.nextLine();
            String[] parts = line.split(" ");
            String subject = parts[0];
            double credit = Double.parseDouble(parts[1]);
            String grade = parts[2];

            if (!grade.equals("P")) {
                totalCredit += credit;

                switch (grade) {
                    case "A+":
                        totalScore += credit * 4.5;
                        break;
                    case "A0":
                        totalScore += credit * 4.0;
                        break;
                    case "B+":
                        totalScore += credit * 3.5;
                        break;
                    case "B0":
                        totalScore += credit * 3.0;
                        break;
                    case "C+":
                        totalScore += credit * 2.5;
                        break;
                    case "C0":
                        totalScore += credit * 2.0;
                        break;
                    case "D+":
                        totalScore += credit * 1.5;
                        break;
                    case "D0":
                        totalScore += credit * 1.0;
                        break;
                    case "F":
                        totalScore += credit * 0.0;
                        break;
                }
            }
        }

        double average = totalScore / totalCredit;

        System.out.printf("%.6f\n", average);
        sc.close();
    }
}
