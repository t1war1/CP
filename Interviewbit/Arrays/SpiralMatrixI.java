public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> spiralOrder(final List<ArrayList<Integer>> A) {
        ArrayList<Integer> ans=new ArrayList<>();
        int r1=0,c1=0,r2=A.size()-1,c2=A.get(0).size()-1;
        while(r1<=r2 && c1<=c2)
        {
                for(int i=c1;i<=c2;i++)
                {
                    ans.add(A.get(r1).get(i));
                }
                for(int i=r1+1;i<=r2;i++)
                {
                    ans.add(A.get(i).get(c2));
                }
                
                if(A.size()!=1)
                for(int i=c2-1;i>=c1;i--)
                {
                    ans.add(A.get(r2).get(i));
                }
                
                if(A.get(0).size()!=1)
                for(int i=r2-1;i>r1;i--)
                {
                    ans.add(A.get(i).get(c1));
                }
                
                r1++;r2--;
                c1++;c2--;
        }
        
        return ans;
            
    }
}