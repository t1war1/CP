package rough;

import java.util.HashMap;

public class PairSumto0 {

	public static void main(String[] args) {
		int[] arr= {2 ,1 ,-2 ,2 ,3};
		PairSum(arr,arr.length);
	}

	public static void PairSum(int[] input, int size) {
		HashMap<Integer,Integer> map=new HashMap<>();
		for(int i=0;i<input.length;i++)
		{
			if(input[i]>=0)
			{
			if(!map.containsKey(input[i]))
			{
				map.put(input[i],1);
			}
			else {
				map.put(input[i], map.get(input[i])+1);
			}
			}
		}
		
		for(int i=0;i<input.length;i++)
		{
			if(input[i]<0)
			{
				if(map.containsKey(input[i]*-1))
				{
					for(int j=0;j<map.get(input[i]*-1);j++)
					{
						System.out.println(input[i]+" "+(input[i]*-1));
					}
				}
			}
		}
	}
	
}
