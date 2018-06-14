public class Solution {
   public static ArrayList<Integer> maxset(ArrayList<Integer> A) {
        
        int sum=0;
        int maxSum=Integer.MIN_VALUE;
        int maxLength=Integer.MIN_VALUE;
        boolean fa=false;
        int l=-1,r=-1,maxl=0,maxr=0;
        for(int i=0;i<A.size();i++)
        {
            if(A.get(i)>=0)
            {
                if(l==-1 || fa)
                {fa=false;
                    l++;
                }
                r++;
                sum+=A.get(i);
                if(i==A.size()-1)
                {
                    if(sum>maxSum)
                    {
                     maxSum=sum;
                     maxLength=r-l+1;
                     maxl=l;maxr=r;
                    }
                    else if(sum==maxSum)
                    {
                        if((r-l+1)>maxLength)
                    {
                        maxl=l;maxr=r;
                    }
                    }
                }
                
            }
            else{
                fa=true;
                if(sum>maxSum)
                {
                    maxSum=sum;
                    maxLength=r-l+1;
                    maxl=l;maxr=r;
                }else if(sum==maxSum){
                    if((r-l+1)>maxLength)
                    {
                        maxl=l;maxr=r;
                    }
                   
                }
                l=i;r=i;sum=0;
            }
            
        }
        
        ArrayList<Integer> ans=new ArrayList<>();
        for(int i=maxl;i<=maxr;i++)
        {
            ans.add(A.get(i));
        }
        return ans;
    }
    
}
