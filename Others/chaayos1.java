import java.util.*;

class Solution {
    public static void main(String[] args) {
        InputStreamReader ip = new InputStreamReader(System.in);
        BufferedReader sc = new BufferedReader(ip);
        int n = Integer.parseInt(sc.readLine());
        int arr[] = new int[n];
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(sc.readLine());
            mp.put(arr[i], 1);
        }
        int m = sc.nextInt();
        int brr[] = new int[m];
        for (int i = 0; i < m; i++) {
            brr[i] = Integer.parseInt(sc.readLine());
            mp.put(brr[i], 2);
        }

        int a[] = new int[n+m];
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }
        for (int i = 0; i < m; i++) {
            a[n+i] = brr[i];
        }
        Collections.sort(a);
        int ans = 0;
        int prev = mp.get(a[0]);
        for (int i = 0; i < n+m; i++) {
            if (mp.get(a[i]) == prev) {
                continue;
            } else {
                prev = mp.get(a[i]);
                ans += 1;
            }
        }
        System.out.println(ans);
    }
}