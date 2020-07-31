import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class cf_1176_d {
    public static int MAXN = (int) 1e7;
    public static int[] isPrime = new int[MAXN];
    public static int[] primeIndex = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sieve();
        int n = sc.nextInt();
        Integer[] arr = new Integer[2 * n];
        int[] count = new int[MAXN];
        for (int i = 0; i < 2 * n; i++) {
            arr[i] = sc.nextInt();
            count[arr[i]] += 1;
        }
        Arrays.sort(arr, Collections.reverseOrder());
        for (int num : arr) {
            if (count[num] > 0) {
                // System.out.println(num);
                count[num] -= 1;
                if (isPrime[num] == 0) {
                    count[primeIndex[num]] -= 1;
                    System.out.print(primeIndex[num] + " ");
                } else {
                    int nexus = num / isPrime[num];
                    // System.out.println(nexus);
                    count[nexus] -= 1;
                    System.out.print(num + " ");
                }
            }
        }
        sc.close();
    }

    public static void sieve() {
        int ind = 0;
        for (int i = 2; i < MAXN; i++) {
            if (isPrime[i] == 0) {
                primeIndex[i] = ++ind;
                for (int j = 2 * i; j < MAXN; j += i) {
                    if (isPrime[j] == 0)
                        isPrime[j] = i;
                }
            }
        }
        isPrime[0] = 1;
        isPrime[1] = 1;
    }
}