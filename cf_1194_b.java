import java.util.Scanner;

public class cf_1194_b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char[][] arr = new char[n][m];
            for (int i = 0; i < n; i++) {
                String s = sc.next();
                arr[i] = s.toCharArray();
            }
            int[] row = new int[n];
            int[] col = new int[m];
            for (int i = 0; i < n; i++) {
                int temp = 0;
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == '.') {
                        temp += 1;
                    }
                }
                row[i] = temp;
            }

            for (int i = 0; i < m; i++) {
                int temp = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j][i] == '.') {
                        temp += 1;
                    }
                }
                col[i] = temp;
            }

            int mn = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mn = Math.min(mn, (arr[i][j] == '.') ? row[i] + col[j] - 1 : row[i] + col[j]);
                }
            }
            System.out.println(mn);
        }
        sc.close();
    }
}