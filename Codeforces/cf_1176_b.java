import java.util.Scanner;

public class cf_1176_b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            int ans = 0, one = 0, two = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                arr[i] %= 3;
                if (arr[i] == 0)
                    ans += 1;
                else if (arr[i] == 1)
                    one += 1;
                else
                    two += 1;
            }
            int mn = Math.min(one, two);
            one -= mn;
            two -= mn;
            ans += mn;
            ans += one / 3;
            ans += two / 3;
            System.out.println(ans);
        }
        sc.close();
    }
}