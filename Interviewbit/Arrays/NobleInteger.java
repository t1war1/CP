public class Solution {
    public int solve(ArrayList<Integer> A) {
        
        Collections.sort(A);
        for(int i=0;i<A.size();i++)
        {
            if(A.get(i)==(A.size()-i-1))
            {
                return 1;
            }
        }
        return -1;
    }
}
