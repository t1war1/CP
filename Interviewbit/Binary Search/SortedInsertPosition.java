package rough;

import java.util.HashMap;

public class PairwithDiffK {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr= {6,6,5};
		findPairsDifferenceK(arr, 1);
	}
	
	public static void findPairsDifferenceK(int[] input, int k){
		HashMap<Integer,Integer> map=new HashMap<>();
		for(int i=0;i<input.length;i++)
		{	
			if(!map.containsKey(input[i]))
			{
				map.put(input[i],1);
			}
			else
			{
				map.put(input[i], map.get(input[i])+1);
			}
		}
		
		for(int i=0;i<input.length;i++)
		{
			int freqSmall=0;
			if(map.containsKey(input[i]-k))
			{
				freqSmall=map.get(input[i]-k);
			}
			if(input[i]==(input[i]-k))
			{
				freqSmall--;
				map.put(input[i], map.get(input[i])-1);
			}
				for(int z=0;z<freqSmall;z++)
				{
					if((input[i]-k)<=input[i])
					System.out.println((input[i]-k)+" "+input[i]);
					else
					System.out.println(input[i]+" "+(input[i]-k));
				}
		}
		
	}
}
