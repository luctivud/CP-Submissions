import java.util.Scanner;

public class Arrays_in_Java {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[2*n] ;
        n = n * 2;
        while (n-- > 0) {
            arr[n] = sc.nextInt();
            System.out.print(n + " " + arr[n] + "\n");
        }
        System.out.println();
    }
}