import java.util.Scanner;

public class cf_1176_a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while (tt-- > 0) {
            long ans = 0;
            long n = sc.nextLong();
            while (true) {
                if (n % 2 == 0) {
                    ans += 1;
                    n /= 2;
                } else if (n % 3 == 0) {
                    ans += 2;
                    n /= 3;
                } else if (n % 5 == 0) {
                    ans += 3;
                    n /= 5;
                } else {
                    break;
                }
            }
            if (n > 1)
                ans = -1;
            System.out.println(ans);
        }
        sc.close();
    }
}