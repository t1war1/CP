package Searching;

import java.util.Scanner;

public class SearchInRotatedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 Scanner s=new Scanner(System.in);
	        int n=s.nextInt();
	        int arr[]=new int[n];
	        for(int i=0;i<n;i++)
	        {
	            arr[i]=s.nextInt();
	        }
	        
	        int t=s.nextInt();
	        for(int i=0;i<t;i++)
	        {
	            int num=s.nextInt();
	            int a=lowerBound(num,arr);
	            int b=UpperBound(num,arr);
	            if(a==Integer.MAX_VALUE)
	            {
	                System.out.print(-1+" ");
	            }
	            else
	            {
	                System.out.print(a+" ");

	            }
	            if(b==Integer.MIN_VALUE)
	            {
	                System.out.print(-1+" ");
	            }
	            else
	            {
	                System.out.println(b);

	            }
	        }
	}
	public static int lowerBound(int num,int[] arr)
    {
        int min=Integer.MAX_VALUE;
        int beg=0,last=arr.length-1;
        while(beg<=last)
        {
            int mid=(beg+last)/2;
            if(arr[mid]==num && mid<min)
            {
                min=mid;
                last=mid-1;
            }
            else if(arr[mid]>num)
            {
                last=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
        return min;
    }
    
    public static int UpperBound(int num,int[] arr)
    {
        int max=Integer.MIN_VALUE;
        int beg=0,last=arr.length-1;
        while(beg<=last)
        {
            int mid=(beg+last)/2;
            if(arr[mid]==num && mid>max)
            {
                max=mid;
                beg=mid+1;
            }
            else if(arr[mid]>num)
            {
                last=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
        return max;
    }
}
