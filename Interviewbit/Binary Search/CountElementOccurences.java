public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int findCount(final List<Integer> A, int B) {
        return findHelp(A,B,0,A.size()-1);
    }
    public static int findHelp(final List<Integer> A, int B,int l,int r)
    {
        if(l>r)
        {
            return 0;
        }
        
        int mid=(l+r)/2;
        int ans=0;
        if(A.get(mid)==B)
        ans++;
        
        return ans+findHelp(A,B,l,mid-1)+findHelp(A,B,mid+1,r);
    }
}
