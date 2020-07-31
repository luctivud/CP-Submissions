import java.util.*;

public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = str.length();
        String target = new String("keyence");
        // System.out.println(n);
        for(int i=0; i<n; i++) {
            for (int j=0; j <n; j++) {
                // remove i to j
                String temp = new String("");
                for (int k=0; k <n; k++) {
                    if (k<i || k >j) temp += str;
                }

                if (temp.equals(target)) {

                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
        sc.close();
    }
}