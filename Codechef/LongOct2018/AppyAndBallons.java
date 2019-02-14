package codeChef.LongOct2018;
import java.util.*;
import java.io.*;
public class AppyAndBallons {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		PrintWriter w=new PrintWriter(System.out);

		int n=s.nextInt();
		long m=s.nextLong();

		Pair arr[]=new Pair[n];
		
		for(int i=0;i<n;i++)
		{
			arr[i]=new Pair();
			arr[i].balloons=s.nextInt();
		}
		long max=Long.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			arr[i].candiesPerBalloon=s.nextInt();
			max=Math.max(max, arr[i].balloons*arr[i].candiesPerBalloon);
		}

		long beg=0,last=max;
		long min=Long.MAX_VALUE;	
		while(beg<=last)
		{
			long mid=(beg+last)/2;
			if(isValid(arr,mid,m))
			{
				min=Math.min(min, mid);
				last=mid-1;
			}
			else
			{
				beg=mid+1;
			}
		}
		w.println(min);
		w.close();
	}
	
	private static boolean isValid(Pair[] arr, long max, long m) {
		for(int i=arr.length-1;i>=0;i--)
		{
			if(arr[i].candiesPerBalloon==0)
			{
				continue;
			}
			long a=(max/arr[i].candiesPerBalloon);
			if(a<arr[i].balloons)
			{
				if((arr[i].balloons-a)>m)
				{
					return false;
				}
				else
				{
					long temp=arr[i].balloons-a;
					m-=temp;
				}
			}
		}
		return true;
	}
}
class Pair{
	long balloons;
	long candiesPerBalloon;
}

