import java.util.Arrays;
import java.util.Scanner;

public class cf_1176_c {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int[] numbers = { 4, 8, 15, 16, 23, 42 };
        // int ans = 0;
        int n = sc.nextInt();
        int[] arr = new int[n];

        int[] subs = new int[6];
        Arrays.fill(subs, 0);
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            int ind = 0;
            for (; ind < 6; ind++) {
                if (arr[i] == numbers[ind])
                    break;
            }
            if (ind == 0)
                subs[0]++;
            else
                subs[ind] = Math.min(subs[ind - 1], subs[ind] + 1);
        }

        System.out.println(n - subs[5] * 6);

        // }
        sc.close();
    }
}