public class Solution {
    public int books(ArrayList<Integer> A, int B) {
        if(A.size()<B)
        {
            return -1;
        }
        int sum=0;
        for(int i=0;i<A.size();i++)
        {
            sum+=A.get(i);
        }
        int beg=0;
        int last=sum;
        int result=Integer.MAX_VALUE;
        
        while(beg<=last)
        {
            int mid= (beg+last)/2;
            if(isPossible(A,B,mid))
            {
                result=Math.min(result,mid);
                last=mid-1;
            }
            else
            {
                beg=mid+1;
            }
        }
        return result;
    }
    
    public static boolean isPossible(ArrayList<Integer> A,int B,int mid)
    {
        
        int studentsRequired = 1;
        int curr_sum = 0;
         for (int i = 0; i < A.size(); i++)
        {
            if (A.get(i) > mid)
                return false;
      
            if (curr_sum + A.get(i) > mid)
            {
                studentsRequired++;
                curr_sum = A.get(i);
      
                if (studentsRequired > B)
                    return false;
            }
                  else
                curr_sum += A.get(i);
        }
        return true;
    }
    
}
