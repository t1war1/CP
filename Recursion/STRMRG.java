package trial;
/*
 * Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)
Output Format :
Count
Constraints :
1 <= a <= 10^5
1 <= b <= 50
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3*/
public class STRMRG {

	public static void main(String[] args) {
		System.out.println(allWays(10,2));
		
	}
	public static int allWays(int x, int n) {
		   /* Your class should be named Solution
			 * Don't write main().
			 * Don't read input, it is passed as function argument.
			 * Return output and don't print it.
		 	 * Taking input and printing output is handled automatically.
			*/
	     return help(1,x,n);
	    }
	  public static int help(int i,int x,int n)
	  {
	    	if(i>=x || x<=0)
	        {
	          if(x==0)
	          {
	            return 1;
	          }
	       		return 0;
	        }
	    	
	    	int small1=help(i+1,x-(int)(Math.pow(i,n)),n);
	    	int small2=help(i+1,x,n);
	    	return small1+small2;
	  }
}
