public class Solution {
    public int solve(String A) {
        int r=A.length()-1;
        while(r>=0)
        {
            if(isPalindrome(A,r))
            {
                int ans=A.length()-r-1;
                return ans;
            }
            r--;
        }
        return 0;
    }
    public static boolean isPalindrome(String A,int r)
    {
        for(int i=0;i<=r;i++,r-- )
        {
            if(A.charAt(i)!=A.charAt(r) )
            {
                return false;
            }
        }
        return true;
    }

}
