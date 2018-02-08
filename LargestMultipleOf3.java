package rough;
/*
 Largest multiple of 3
 Send Feedback
 An array of nonnegative single digit integers is given. Find the largest multiple of 3 that can be formed from the elements that are present in array.
 For example, if the input array is {8, 1, 9}, the output should be “9 8 1″, and if the input array is {8, 1, 7, 6, 0}, output should be “8 7 6 0″.
 Input format :
 Line 1 : Size of input array
 Line 2 : Array elements (separated by space)
 Sample Input :
 3
 8 1 9
 Sample Output :
 9 8 1
 */
import java.util.ArrayList;
import java.util.Comparator;

public class LargestMultipleOf3 implements Comparator<Integer>{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer>list =new ArrayList<>();
		list.add(8);
		list.add(1);
		list.add(7);
		list.add(6);
		list.add(0);
		ArrayList<Integer> ans=largestMultiple3(list);
		for(Integer i:ans) {
			System.out.print(i+" ");
		}
	}
	
public static ArrayList<Integer> largestMultiple3(ArrayList<Integer> input) {
      int sum=0;
      input.sort(new LargestMultipleOf3());
		for(int i=0;i<input.size();i++)
        {
			sum+=input.get(i);
        }
		if(sum%3==1)
		{
			int temp=-1;
			for(int i=0;i<input.size();i++)
			{
				if(input.get(i)%3==1)
				{
					input.remove(i);
					temp=0;
					break;
				}
			}
			if(temp==-1)
			{
				int n1=-1,n2=-1;
				for(int i=0;i<input.size();i++)
				{
					if(input.get(i)%3==2)
					{
						if(n1==-1)
						{
							n1=i;
						}
						else if(n2==-1)
						{
							n2=i;
						}
					}
				}
				if(n1!=-1 && n2!=-1)
				{
					input.remove(n1);
					input.remove(n2);
				}
			}
		}
		else if(sum%3==2)
		{
			int temp=-1;
			for(int i=0;i<input.size();i++)
			{
				if(input.get(i)%3==2)
				{
					input.remove(i);
					temp=0;
					break;
				}
			}
			
			if(temp==-1)
			{
				int n1=-1,n2=-1;
				for(int i=0;i<input.size();i++)
				{
					if(input.get(i)%3==1)
					{
						if(n1==-1)
						{
							n1=i;
						}
						else if(n2==-1)
						{
							n2=i;
						}
					}
				}
				if(n1!=-1 && n2!=-1)
				{
					input.remove(n1);
					input.remove(n2);
				}
			}
		}
		for(int i=input.size()-1,j=0;i>=input.size()/2;i--,j++)
		{
			int temp=input.get(i);
			input.set(i,input.get(j));
			input.set(j,temp);
		}
		return input;
	}


	public int compare(Integer o1, Integer o2) {
		// TODO Auto-generated method stub
		return o1.compareTo(o2);
	}
}
