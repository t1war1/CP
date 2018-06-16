public class Solution {
    // DO NOT MODIFY THE LIST
    public ArrayList<Integer> searchRange(final List<Integer> a, int b) {
        ArrayList<Integer> ans=new ArrayList<>();
        int ans1=lowerBound(b,a);
        if(ans1==Integer.MAX_VALUE)
        ans.add(-1);
        else
        ans.add(ans1);
        
        int ans2=UpperBound(b,a);
        if(ans2==Integer.MIN_VALUE)
        ans.add(-1);
        else
        ans.add(ans2);
        return ans;
    }
     public static int lowerBound(int num,final List<Integer> a)
    {
        int min=Integer.MAX_VALUE;
        int beg=0,last=a.size()-1;
        while(beg<=last)
        {
            int mid=(beg+last)/2;
            if(a.get(mid)==num && mid<min)
            {
                min=mid;
                last=mid-1;
            }
            else if(a.get(mid)>num)
            {
                last=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
        return min;
    }
    
    public static int UpperBound(int num,final List<Integer> a)
    {
        int max=Integer.MIN_VALUE;
        int beg=0,last=a.size()-1;
        while(beg<=last)
        {
            int mid=(beg+last)/2;
            if(a.get(mid)==num && mid>max)
            {
                max=mid;
                beg=mid+1;
            }
            else if(a.get(mid)>num)
            {
                last=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
        return max;
    }
}
