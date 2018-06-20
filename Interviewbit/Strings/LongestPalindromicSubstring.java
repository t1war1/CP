public class Solution {
    public String longestPalindrome(String A) {
            
        if(A.length()==0)
        {
            return "";
        }
        int maxLength=1;
        String ans="a";
        for(int k=1;k<A.length();k++)
        {
            int low=k-1,high=k+1;
            while(low>=0 && high<A.length() && A.charAt(low)==A.charAt(high))
            {
                if(high-low+1>maxLength)
                {
                    ans=A.substring(low, high+1);
                    maxLength=high-low+1;
                }
                low--;high++;
            }
            
            low=k-1;high=k;
            while(low>=0 && high<A.length() && A.charAt(low)==A.charAt(high))
            {
                if(high-low+1>maxLength)
                {
                    ans=A.substring(low, high+1);
                    maxLength=high-low+1;
                }
                low--;high++;
            }
        }
        return ans;
    }
}
