import java.util.Scanner;

public class ok_prc {
    final static Scanner sc = new Scanner(System.in);
    public static void main (final String[] args) {
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i =0; i<n; i++) {
            a[i] = sc.nextInt();
            // char temp = sc.next();
            b[i] = sc.nextInt();
        }

        double perimeter = 0.0;
        // double mx = -1.1;
        for (int i=0; i<n; i++) {
            double side = Math.sqrt(Math.pow((a[i]-a[(i+1)%n]), 2) + Math.pow(b[i]-b[(i+1)%n], 2));
            // mx = Math.max(mx, side);
            perimeter += side;
        }
        System.out.println(perimeter);
    }
    
    public static void solve(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            System.out.println(t + " ");
        }
    }
}

