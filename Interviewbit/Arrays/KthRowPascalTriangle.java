public class Solution {
    public ArrayList<Integer> getRow(int A) {
        
        A++;
            ArrayList<Integer> ans=new ArrayList<>();
            for(int i=0;i<A;i++)
            {
                ans.add(0);
            }
            ans.set(0,1);
            int temp=0;
            for(int i=0;i<A;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    if(j==0)
                    {
                        temp=1;    
                        continue;
                    }
                    int t=ans.get(j);
                    ans.set(j, ans.get(j)+temp);
                    temp=t;
                }
            }
            return ans;
    }
}
