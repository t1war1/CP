public class Solution {
    public String convert(String A, int B) {
        if(A.length()<2 || B==1)
            return A;
        String ans="";
        for(int i=0;i<B;i++)
        {
            int next=i;
            int even=1;
            while(next<A.length())
            {
                ans+=A.charAt(next);
                if(i==0 || i==B-1)
                {
                    next+=(B-2)*2+2;    
                }
                else
                {
                    if(even==1)
                    {
                        next+=(B-i-2)*2+2;
                        even =0;
                    }
                    else
                    {
                        next+=i*2;
                        even=1;
                    }
                }
            }
        }
        return ans;
    }
}
