public class Solution {
    public int coverPoints(ArrayList<Integer> A, ArrayList<Integer> B) {
        int ans=0;
        
        for(int i=0;i<A.size()-1;i++)
        {
            int x1=A.get(i);
            int y1=B.get(i);
            int x2=A.get(i+1);
            int y2=B.get(i+1);
            
            if(Math.abs(x1-x2) == Math.abs(y1-y2))
            {
                ans+= Math.abs(x1-x2) ;
            }
            else if(x1==x2 || y1==y2){
                 ans+= Math.abs(x1-x2) + Math.abs(y1-y2);
            }
            else
            {
                int a=Math.abs(x1-x2);
                int b=Math.abs(y1-y2);
                
                if(a<b)
                {
                    if(y1<y2)
                        ans+=a + Math.abs(y1+a-y2);
                        else
                        ans+=a + Math.abs(y1-a-y2);
                    
                }else{
                    if(x1<x2)
                         ans+=b+Math.abs(x1+b-x2) ;
                         else
                         ans+=b+Math.abs(x1-b-x2) ;
                }
            }
        }
        return ans;
    }
}
