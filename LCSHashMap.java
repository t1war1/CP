package rough;

import java.util.*;

public class LCSHashMap {

	public static void main(String[] args) {
		int arr[]= {15 ,13 ,23 ,21 ,19 ,11 ,16};
		ArrayList<Integer> ans=longestSubsequence(arr);
		for(int i:ans)
		{
			System.out.print(i+" ");
		}
	}

	public static ArrayList<Integer> longestSubsequence(int[] arr)
	{
		HashSet<Integer> hashset=new HashSet<>();
		for(int i:arr)
		{
			hashset.add(i);
		}
			
		int start=-1,length=Integer.MIN_VALUE;
		
		for(int i=0;i<arr.length;i++)
		{
			if(!hashset.contains(arr[i]-1)) 
			{
				int beg=arr[i];
				while(hashset.contains(beg))
				{
					beg++;
				}
				if((beg-arr[i])>length)
				{
//					startIndex=i;
					start=arr[i];
					length=beg-start;
				}
				
			}
		}
		
		ArrayList<Integer> ans=new ArrayList<>();
		for(int i=0;i<length;i++)
		{
			ans.add(start+i);
		}
		return ans;
	}
}
