package rough;

/*
 * Increasing Numbers
Send Feedback
Print all n digit increasing numbers in increasing order.
Numbers you print should be in increasing order and only those numbers should be printed which have digits in increasing order.
Sample Input
2
Sample Output
12 13 14 15 16 17 18 19 23 24 25 26 27 28 29 34 35 36 37 38 39 45 46 47 48 49 56 57 58 59 67 68 69 78 79 89 */
public class IncreasingNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		printIncreasingNumber(3);
	}
	public static void printIncreasingNumber(int n) {
		helper(0,n)	;
	}
	public static void helper(int k,int n)
    {
      if(n==0)
      {
        System.out.print(k+" ");
      }
      	for(int i=1;i<10;i++)
        {
          if(k==0 || i>(k%10))
          helper((k*10)+i,n-1);
        }
    }
}
