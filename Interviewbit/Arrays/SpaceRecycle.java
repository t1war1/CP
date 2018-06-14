public class Solution {
    public void setZeroes(ArrayList<ArrayList<Integer>> a) {
        if(a.size()==0 ||a.get(0).size()==0)
        return;
        HashSet<Integer> rows=new HashSet<>();
        HashSet<Integer> cols=new HashSet<>();
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a.get(0).size();j++)
            {
                if(a.get(i).get(j)==0)
                {
                    rows.add(i);cols.add(j);
                }
            }
        }
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a.get(0).size();j++)
            {
                if(rows.contains(i) || cols.contains(j))
                {
                    a.get(i).set(j,0);
                }
            }
        }
        
    }
}
