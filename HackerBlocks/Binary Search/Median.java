import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int arr1[]=new int[n],arr2[]=new int[n];
		for(int i=0;i<n;i++)
		{
			arr1[i]=s.nextInt();
		}
		for(int i=0;i<n;i++)
		{
			arr2[i]=s.nextInt();
		}
		int mid1=n;int first=0,second =0;
		int i=0,j=0,k=0, count=0;
		int finalArray[]=new int[2*n];
		while(i<n && j<n)
		{
			if(arr1[i]<=arr2[j])
			{
				finalArray[k++]=arr1[i++];
			}
			else
			{
				finalArray[k++]=arr2[j++];
			}
		}
		
		while(i<n)
		{
			finalArray[k++]=arr1[i++];
		}
		while(j<n)
		{
			finalArray[k++]=arr2[j++];
		}
		
		System.out.println((finalArray[n-1]+finalArray[n])/2);
    }
}
