import java.util.*;

public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        while (k > 0) {
            if ((n % 10) == 0) {
                n /= 10;
            } else {
                n -= 1;
            }
            k -= 1;
            // System.out.println(n);
        }
        System.out.println(n);
        sc.close();
    }
}