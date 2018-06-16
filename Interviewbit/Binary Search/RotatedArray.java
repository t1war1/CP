public class Solution {
    // DO NOT MODIFY THE LIST
    public int findMin(final List<Integer> a) {

        for(int i=0;i<a.size()-1;i++)
        {
            if(a.get(i)>a.get(i+1))
            {
                return a.get(i+1);
            }
        }
        return a.get(0);
    }
}
