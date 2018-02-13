package dnvd;

import java.util.Scanner;

public class LIS {
	
public static void lcs(int a[]){
		
		int ans[] = new int[a.length];
		ans[0]=1;
		for(int i=1;i<a.length;i++)
		{
			int max=0;
			for(int j=0;j<=i-1;j++)
			{
				if(a[i]>a[j])
				{
					if(ans[j]>max)
						max=ans[j];
				}
			}
			ans[i]=max+1;
		}
		for(int i=0;i<ans.length;i++)
		{
			System.out.print(ans[i]+" ");
		}
	}
	public static void main(String[] args) {

		int a[] = {10,22,9,33,21,50,41,60};		
		lcs(a);
	}
}
