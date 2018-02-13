package dnvd;

public class staircase {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(staircaseRec(3));
		System.out.println(staircaseDP(3));
	}

	private static int staircaseRec(int n) {
		
		if(n<=0) {
			return 1;
		}
		else if(n==1) {
			return 1;
		}
		else if(n==2)
		{
			return 2;
		}
		
		return staircaseRec(n-1)+staircaseRec(n-2)+staircaseRec(n-3);
	}
	
	static int staircaseDP(int n)
	{
		 int dp[] = new int[n+1];
	        dp[0] = 1; dp[1] = 1;dp[2]=2;
	        for (int i=3; i<=n; i++)
	        {
	           dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	        }
	        return dp[n];
	}
	
}
