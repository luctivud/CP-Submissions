import java.oi.*;
class Solution{
    public static int solve(int arr[],int n,int sum)
    {
        int ws=0,wsum=0,minLength=Integer.MAX_VALUE;
        for(int we=0;we<n;we++)
        {
            wsum += srr[we];
            while(wsum>=sum)
            {
                minLength=Math.min(minLength,we-ws+1);
            wsum-=arr[ws];
            ws++;}
        }
      return minLength;
    }
}

public class 0x02i39 {
    public static void main(String args[]){
        int arr[]={23,2,6,4,7};
        int n=5;
        int ans= new Solution().solve(arr,n,6);
        System.out.println(ans);
    }
}
