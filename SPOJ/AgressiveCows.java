import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int c=s.nextInt();
        int beg=0,last=Integer.MIN_VALUE;
        int stalls[]=new int[n];
        for(int i=0;i<n;i++)
        {
            stalls[i]=s.nextInt();
        }
        Arrays.sort(stalls);
        beg=stalls[0];
        last=stalls[n-1];
        int ans=Integer.MIN_VALUE;
        while(beg<=last)
        {
            int mid=(beg+last)/2;
            if(isValid(stalls,mid,c))
            {
                ans=mid;
                beg=mid+1;
            }
            else{
                last=mid-1;
            }
        }
        System.out.println(ans);
    }
    
    public static boolean isValid(int[] stalls, int dist,int cows)
    {
        cows--;
        int prev=stalls[0];
        for(int i=1;i<stalls.length;i++)
        {
            if(stalls[i]>=prev+dist)
            {
                cows--;
                prev=stalls[i];
            }
            if(cows==0)
            {
                return true;
            }
        }
        return false;
    }
}