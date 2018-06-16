public class Solution {
    public int searchMatrix(ArrayList<ArrayList<Integer>> a, int b) {
        
        for(int i=0;i<a.size();i++)
        {
            ArrayList<Integer> curr=a.get(i);
            int beg=0,last=a.get(0).size()-1,result=-1;
            while(beg<=last)
            {
                int mid=(beg+last)/2;
                if(a.get(i).get(mid)==b)
                {
                    result=mid;
                    break;
                }
                else if(a.get(i).get(mid)>b)
                {
                    last=mid-1;
                }
                else
                {
                    beg=mid+1;
                }
            }
            if(result!=-1)
                return 1;
        }
        return 0;
        
    }
}
