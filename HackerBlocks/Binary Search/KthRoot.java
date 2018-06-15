import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);        
        int t=s.nextInt();
        for(int i=0;i<t;i++)
        {
        		long n=s.nextLong();
        		int k=s.nextInt();
        		System.out.println(kthRoot(n, k));
        }
    }
    
    public static long kthRoot(long n,int k)
	{
		long beg=1,last=n;
		long ans=0;
		while(beg<=last)
		{
			long mid=(beg+last)/2;
			long temp=(long)Math.pow(mid,k);
			if(temp==n)
			{
				ans=mid;
				break;
			}
			else if(temp>n)
			{
				last=mid-1;
			}
			else
			{
				beg=mid+1;
				ans=mid;
			}
		}
		return ans;
	}
    
}
