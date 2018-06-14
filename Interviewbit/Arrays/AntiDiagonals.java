public class Solution {
    public ArrayList<ArrayList<Integer>> diagonal(ArrayList<ArrayList<Integer>> A) {
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();

        for(int i=0;i<A.get(0).size();i++)
        {
            ArrayList<Integer> temp=new ArrayList<>();
            for(int row=0,col=i;row<A.size() && col>=0;row++,col-- )
            {
                temp.add(A.get(row).get(col));
            }
            ans.add(temp);
        }
        
        for(int j=1;j<A.size();j++)
        {
            ArrayList<Integer> temp=new ArrayList<>();
            for(int row=j,col=A.get(0).size()-1;row<A.size() && col>=0;row++,col-- )
            {
                temp.add(A.get(row).get(col));
            }
            ans.add(temp);
        }
        return ans;
    }
}
