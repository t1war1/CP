package dnvd;

public class knapsack {

	public static void main(String[] args) {
		int values[]= {10, 20, 30};
		int weights[]= {1, 1, 1};
		System.out.println(knapsackRec(weights,values,2,0));
		System.out.println(knapsackDP(weights,values,2));
	}

	//bekaar knapsack
	 static int knapsackRec(int[] weights, int[] values, int capacity,int index) {
		 if(index==weights.length || capacity==0)
		 {
			 return 0;
		 }
		 
		 if(weights[index]>capacity)
		 {
			 return knapsackRec(weights, values, capacity, index+1);
		 }
		int ans1=values[index]+knapsackRec(weights,values,capacity-weights[index],index+1);
		int ans2=knapsackRec(weights, values, capacity, index+1);
		
		return Math.max(ans1, ans2);
	}
	 
	 //badiya knapsack
	 static int knapsackDP(int[] weights,int[] values,int capacity)
	 {
		 int[][] dp=new int[weights.length+1][capacity+1];
		 for(int i=0;i<=weights.length;i++)
		 {
			dp[i][0]=0;
		 }
		 
		 for(int i=0;i<capacity;i++)
		 {
			 dp[0][i]=0;
		 }
		 
		 for(int i=1;i<=weights.length;i++)
		 {
			 for(int j=1;j<=capacity;j++)
			 {	 
				 if(weights[i-1]>j)
				 {
					 dp[i][j]=	dp[i-1][j];
				 }else {
					 dp[i][j]=Math.max((values[i-1]+ dp[i-1][j-weights[i-1]]),dp[i-1][j]);
				 }
			 }
		 }
		 return dp[weights.length][capacity];
		 
	 }
	 

}
