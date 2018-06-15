package Searching;

import java.util.Scanner;

public class SearchInRotatedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 Scanner s=new Scanner(System.in);
	     int painters=s.nextInt();
	     int boards=s.nextInt();
	     int beg=-1,last=0;
	     int arr[]=new int[boards];
	     for(int i=0;i<boards;i++)
	     {
	    	 	arr[i]=s.nextInt();
	    	 	beg=Math.max(beg, arr[i]);
	    	 	last+=arr[i];
	     }
	     int ans=Integer.MIN_VALUE;
	     while(beg<=last)
	     {
	    	 	int mid=(beg+last)/2;
	    	 	if(isValid(arr,painters,mid))
	    	 	{
	    	 		ans=mid;
	    	 		last=mid-1;
	    	 	}
	    	 	else
	    	 	{
	    	 		beg=mid+1;
	    	 	}
	     }
	     System.out.println(ans);
	}
	public static boolean isValid(int[] arr,int painters,int time)
	{
		int ans=1,sum=0,i=0;
		while(i<arr.length)
		{
			sum+=arr[i];
			if(sum>time)
			{
				sum=0;
				ans++;
			}
			else
			{
				i++;
			}
		}
		if(ans<=painters)
			return true;
		return false;
	}
	
}
