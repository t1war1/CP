public class Solution {
    public String longestCommonPrefix(ArrayList<String> A) {
        int len=Integer.MAX_VALUE;
        for(int i=0;i<A.size();i++)
        {
            if(A.get(i).length() <len )
            {
                len=A.get(i).length();
            }
        }
        String ans="";
        for(int i=0;i<len;i++)
        {
            char ch=A.get(0).charAt(i);
            int j;
            for( j=1;j<A.size();j++ )
            {
                if(A.get(j).charAt(i)!=ch )
                {
                    break;
                }
            }
            if(j==A.size() )
            {
                ans+=ch;
            }
            else
            {
                break;
            }
            
        }
        return ans;
        
    }
}
