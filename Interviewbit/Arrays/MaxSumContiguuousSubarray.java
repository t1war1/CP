public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int maxSubArray(final List<Integer> A) {
        
        int maxSum=Integer.MIN_VALUE,currentSum=0;
        for(int i=0;i<A.size();i++)
        {
            currentSum=currentSum+A.get(i);
            if(currentSum>maxSum)
            {
                maxSum=currentSum;
            }
            if(currentSum<0)
            currentSum=0;
        }
        return maxSum;
        
        
    }
}
