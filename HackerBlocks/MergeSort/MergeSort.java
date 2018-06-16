package Searching;

import java.util.*;

	
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
		mergeSort(arr);
		for(int i:arr)
		{
			System.out.print(i+" ");
		}
	}

	public static void mergeSort(int[] arr) {
		if(arr.length<2)
			return;
		int mid=(arr.length-1)/2;
		int arr1[]=new int[mid+1];
		int arr2[]=new int[arr.length-mid-1];
		for(int i=0;i<arr1.length;i++)
		{
			arr1[i]=arr[i];
		}
		for(int i=arr1.length;i<arr.length;i++)
		{
			arr2[i-arr1.length]=arr[i];
		}
		mergeSort(arr1);
		mergeSort(arr2);
		merge(arr,arr1,arr2);
	}

	private static void merge(int[] arr, int[] arr1, int[] arr2) {
		int i=0,j=0,k=0;
		while(i<arr1.length && j<arr2.length)
		{
			if(arr1[i]<=arr2[j])
			{
				arr[k++]=arr1[i++];
			}
			else
			{
				arr[k++]=arr2[j++];
			}
		}
		while(i<arr1.length)
		{
			arr[k++]=arr1[i++];
		}
		while(j<arr2.length)
		{
			arr[k++]=arr2[j++];
		}
	}		

}
