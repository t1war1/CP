package dnvd;

import java.util.Scanner;

public class MinSteps {

	public static int minSteps(int n) {

		if(n<=1)
			return 0;
		int a=minSteps(n-1);
		int b = Integer.MAX_VALUE,c=Integer.MAX_VALUE;
		if(n%2==0)
			b = minSteps(n/2);
		if(n%3==0)
			c = minSteps(n/3);

		return Math.min(a, Math.min(b, c))+1;
	}
	public static int minSteps1(int n,int ans[]) {

		if(n<=1)
			return 0;
		if(ans[n]!=0)
			return ans[n];
		int a=minSteps1(n-1,ans);
		int b = Integer.MAX_VALUE,c=Integer.MAX_VALUE;
		if(n%2==0)
			b = minSteps1(n/2,ans);
		if(n%3==0)
			c = minSteps1(n/3,ans);

		ans[n]=Math.min(a, Math.min(b, c))+1;
		return ans[n];
	}
	public static int minSteps2(int n){

		int ans[] = new int[n+1];
		ans[0]=0;
		ans[1]=0;
		for(int i=2;i<=n;i++)
		{
			int x = ans[i-1],y=Integer.MAX_VALUE,z=Integer.MAX_VALUE;
			if(i%2==0)
			{
				y=ans[i/2];
			}
			if(i%3==0)
				z=ans[i/3];
			
			ans[i]=Math.min(x, Math.min(y, z))+1;
		}
		return ans[n];

	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		int ans[] = new int[t+1];
		System.out.println(minSteps2(t));
		//System.out.println(minSteps1(t,ans));
		//System.out.println(minSteps(t));
		
		

	}

}
