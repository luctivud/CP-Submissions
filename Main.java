import java.util.*;

public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while (t-- > 0) {
            int n = sc.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextLong();
            }

            boolean ok = true;
            long sum = 0L;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
                if (sum <= 0L) {
                    ok = false;
                    break;
                }
            }

            sum = 0L;
            for (int i = n - 1; i >= 0; i--) {
                sum += arr[i];
                if (sum <= 0) {
                    ok = false;
                    break;
                }
            }

            System.out.println((ok) ? "YES" : "NO");
        }
        sc.close();
    }
}

// longernet is slow and weird so why be idle and wait for the webpage to load when I can just reproduce the same in Java.
// 22:45 2Aug2020 . Also waiting for my mango shake. @ home.