package trial;

import java.util.*;
 
 public class Trial2 {

	 
	 
	 public static void main(String[] args) {
		 Scanner s=new Scanner(System.in);
		 int t=s.nextInt();
		 for(int i=0;i<t;i++)
		 {
			 int n=s.nextInt();
			 int [][] arr=new int[n][n];
			 for(int j=0;j<n;j++)
			 {
				 for(int k=0;k<n;k++)
				 {
					 arr[j][k]=s.nextInt();
				 }
			 }
			 
			 int flag=0;
			 long sum=0;
			 int prev=Integer.MAX_VALUE;
			 for(int j=n-1;j>=0;j--)
			 {
				 int currMax=Integer.MIN_VALUE;
				 for(int k=0;k<n;k++)
				 {
					 if(arr[j][k]>currMax && arr[j][k]<prev)
					 {
						 currMax=arr[j][k];
					 }
				 }
				 if(currMax==Integer.MIN_VALUE)
				 {
					 System.out.println(-1);
					 flag=1;
					 break;
				 }
				 sum+=currMax;
				 prev=currMax;
			 }
			 if(flag==0)
			 System.out.println(sum);
		 }
	}
}
 