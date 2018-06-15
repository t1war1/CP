import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
            int n=s.nextInt();
            int m=s.nextInt();
            int arr[]=new int[n];
            for(int j=0;j<n;j++)
            {
                arr[j]=s.nextInt();
            }
            Arrays.sort(arr);
            System.out.println(findPages(arr,n,m));
        
    }
     	 static int findPages(int arr[], int n, int m)
	    {
	        long sum = 0;

	        if (n < m)
	            return -1;
	      
	        for (int i = 0; i < n; i++)
	            sum += arr[i];
	        
	        int start = 0, end = (int) sum;
	        int result = Integer.MAX_VALUE;
	      
	        
	        while (start <= end)
	        {
	            int mid = (start + end) / 2;
	            if (isPossible(arr, m, mid))
	            {
	                result = Math.min(result, mid);
	                end = mid - 1;
	            }
	      
	            else
	                start = mid + 1;
	        }
	              return result;
	    }
	    
	    static boolean isPossible(int[] arr,int m,int pages)
	    {
	        int ans=1,sum=0,i=0;
	        while(i<arr.length)
	        {
	            sum+=arr[i];
	            if(sum>pages)
	            {
	                sum=0;
	                ans++;
	            }
	            else
	            {
	                i++;
	            }
	        }
	        if(ans<=m)
	        	return true;
	        return false;
}}
