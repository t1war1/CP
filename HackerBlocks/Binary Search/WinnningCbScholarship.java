package Searching;

import java.util.Scanner;
	
public class SearchInRotatedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int m=s.nextInt();
		int x=s.nextInt();
		int y=s.nextInt();
		int ans=0;
		int beg=0,last=n;
		while(beg<=last)
		{
			int mid=(last+beg)/2;
			if(isValid(m,n,x,y,mid))
			{	
				ans=mid;
				beg=mid+1;
			}
			else
			{
				last=mid-1;
			}
		}
		System.out.println(ans);
	}		
	public static boolean isValid(int m,int n,int x,int y,int mid)
	{
		return mid*x<=m+(n-mid)*y;
	}
}
